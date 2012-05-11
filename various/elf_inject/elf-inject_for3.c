#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

extern int errno;

int main (int argc, char **argv)
{
	int 		fd, res, i, sym_num;
	char		*sym_table;
	Elf32_Ehdr	elfh;
	Elf32_Shdr	sech, sym_sec, symt_sec;
	Elf32_Sym	symb;

	if (argc < 2) {
		printf("[ERR] wrong format need ./a.out symbol addr\n");
		exit(1);
	}

	fd = open("simple.ko", O_RDWR);
	if (fd < 0 ) {
		printf("[ERR] cannot open elf file. errno: %s\n", strerror(errno));
		exit(1);
	}

	res = read(fd, &elfh, sizeof(elfh));
	if (res < sizeof(elfh)) {
		printf("[ERR] cannot read elf file. errno: %s\n", strerror(errno));
		exit(1);
	}
	printf("elf open...OK\n");

	if (strncmp((char *)elfh.e_ident, ELFMAG, SELFMAG)) {
		printf("[ERR] broken ELF tag:0x%x%c%c%c\n", elfh.e_ident[0], elfh.e_ident[1], elfh.e_ident[2], elfh.e_ident[3]);
		exit(1);
	}
	printf("check elf...OK\n");

	printf("Number of sections inside elf: %d\n", elfh.e_shnum);

	lseek(fd, elfh.e_shoff, SEEK_SET);
	for (i=0; i<elfh.e_shnum; i++) {
		res = read(fd, &sech, sizeof(sech));
		if (res < sizeof(sech)) {
			printf("[ERR] cannot read section inside elf file. errno: %s\n", strerror(errno));
			exit(1);
		}

		if (sech.sh_type == SHT_SYMTAB)
			break;
	} // for(i=0)

	if (i==elfh.e_shnum) {
		printf("[ERR] cannot find SYMTAB section\n");
		goto out;
	};

	/* store .symtab section */
	sym_sec = sech;
	i++;

	/* FIXME - dont know, but seems this section strictly after .symtab */
	for (; i<elfh.e_shnum; i++) {
		res = read(fd, &sech, sizeof(sech));
		if (res < sizeof(sech)) {
			printf("[ERR] cannot read section inside elf file. errno: %s\n", strerror(errno));
			exit(1);
		}

		if(sech.sh_type == SHT_STRTAB) {
			symt_sec = sech;
			printf("found STRTAB section id:%d offs:0x%06x... Ok\n", i, symt_sec.sh_offset);
		}
	}

	/* FIXME - add check for presented STRTAB */
	sym_table = malloc(symt_sec.sh_size);
	lseek(fd, symt_sec.sh_offset, SEEK_SET);
	res = read(fd, sym_table, symt_sec.sh_size);
	if (res < symt_sec.sh_size) {
		printf("[ERR] cannot read symbol table inside elf file. errno: %s\n", strerror(errno));
		exit(1);
	}

	/* get symbols */
	sym_num = sym_sec.sh_size / sizeof(symb);
	printf("found symtab section id:%d number of symbols:%d...OK\n", i, sym_num);
	
	lseek(fd, sym_sec.sh_offset, SEEK_SET);
	for (i=0; i<sym_num; i++) {
		res = read(fd, &symb, sizeof(symb));
		if (res < sizeof(symb)) {
			printf("[ERR] cannot read symbol inside elf file. errno: %s\n", strerror(errno));
			exit(1);
		}

		//printf("%d: st_name:%d\t%s\n", i, symb.st_name, sym_table + symb.st_name);

		if(!strcmp(sym_table + symb.st_name, argv[1])) {
			char	*st_name_ptr = sym_table + symb.st_name;
			printf("found %s symbol id:%d\n", st_name_ptr, i);
			
			/* write it */
			lseek(fd, sym_sec.sh_offset + sizeof(symb) * i, SEEK_SET);
			sscanf(argv[2], "0x%x", &symb.st_value);
			res = write(fd, &symb, sizeof(symb));
			if (res < sizeof(symb)) {
				printf("[ERR] cannot patch elf file. errno: %s", strerror(errno));
				goto out;
			}
			printf("elf patched...Ok\n");
			break;
		}
	} // for(i=0)

	if (i == sym_num) {
		printf("[ERR] symbol not found\n");
		goto out;	
	}

out:
	/* destroy */
	close(fd);
	
	return 0;
}
