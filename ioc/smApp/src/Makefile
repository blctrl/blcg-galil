TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = sm
# sm.dbd will be created and installed
DBD += sm.dbd

# sm.dbd will be made up from these files:
sm_DBD += base.dbd
sm_DBD += asyn.dbd
sm_DBD += drvAsynSerialPort.dbd
sm_DBD += drvAsynIPPort.dbd
sm_DBD += motorSupport.dbd
sm_DBD += devSoftMotor.dbd
sm_DBD += calcSupport.dbd
sm_DBD += sscanSupport.dbd
sm_DBD += asSupport.dbd
sm_DBD += busySupport.dbd
sm_DBD += GalilSupport.dbd

# Include dbd files from all support applications:
#sm_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#sm_LIBS += xxx
sm_LIBS += asyn motor calc sscan autosave busy
sm_LIBS += GalilSupport
sm_LIBS += softMotor

# sm_registerRecordDeviceDriver.cpp derives from sm.dbd
sm_SRCS += sm_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
sm_SRCS_DEFAULT += smMain.cpp
sm_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#sm_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
sm_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

