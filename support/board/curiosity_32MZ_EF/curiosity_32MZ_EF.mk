
DEVICE = 32MZ2048EFM100
ARCHI = pic32mzef

DEV_PROG ?= PKOB

vpath %.c $(dir $(lastword $(MAKEFILE_LIST)))
vpath %.h $(dir $(lastword $(MAKEFILE_LIST)))

SRC += curiosity_32MZ_EF.c
HEADER += curiosity_32MZ_EF.h
ARCHI_SRC += fuses.c