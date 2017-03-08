
AS = xc16-as
CC = xc16-gcc
LD = xc16-ld
LDFLAGS_XC += -Wl,--heap=$(HEAP),-Tp$(DEVICE).gld
AR = xc16-ar
HX = xc16-bin2hex
SIM = sim30
OBJDUMP = xc16-objdump

CCFLAGS += -Wall
CCFLAGS_XC += -no-legacy-libc
CCFLAGS_XC += -mcpu=$(DEVICE)
CCFLAGS_XC += -mno-eds-warn

-include $(RTPROG)/support/archi/microchip/microchip.mk
