
BOARDPATH = $(dir $(lastword $(MAKEFILE_LIST)))

# check ROBOT variable exists
ifdef ROBOT
 ROBOT_FILE = $(UDEVKIT)/support/robot/$(ROBOT)/$(ROBOT).mk

 # check ROBOT_FILE exists
 ifeq ("$(wildcard $(ROBOT_FILE))","")
  $(error Invalid ROBOT name)
 endif

 # include the robot file
 include $(ROBOT_FILE)

 INCLUDEPATH += -I$(UDEVKIT)/support/robot/$(ROBOT)/
endif
