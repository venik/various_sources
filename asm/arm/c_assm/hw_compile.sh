#!/bin/sh

arm-linux-gnueabi-as -alh -o hw.o hw.S > hw.ls
arm-linux-gnueabi-ld --strip-all -o hw hw.o
