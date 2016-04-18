
ARCHIPATH = $(dir $(lastword $(MAKEFILE_LIST)))

# check ARCHI variable exists
ifndef ARCHI
 $(error Invalid ARCHI in board definition)
endif

ARCHI_FILE = $(RTPROG)/support/archi/$(ARCHI)/$(ARCHI).mk

# check BOARD_FILE exists 
ifeq ("$(wildcard $(ARCHI_FILE))","")
 $(error Invalid ARCHI name)
endif

DEFINES += -DARCHI_$(ARCHI) -DDEVICE_$(DEVICE)

# include the achitechture file
include $(ARCHI_FILE)