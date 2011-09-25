; ----- ex.s -----
; arm-none-linux-gnueabi-gcc -E ex.S > p_ex.s

#include "my_header.h"

	AREA Example, CODE, READONLY

start
	MOV   r0, #ONE_CONSTANT
	ADD   r0, r0, r1
	MOV   pc,lr

	END
--- end ex.s ---
