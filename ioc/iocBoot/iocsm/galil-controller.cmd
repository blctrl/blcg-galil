#Load motor records for real and coordinate system (CS) motors
dbLoadTemplate("Db/blc_motors.substitutions")

#Load extra features that have controller wide scope (eg.  Limit switch type, home switch type, output compare, message consoles)
dbLoadTemplate("Db/blc_ctrl_extras.substitutions")

#Load extra features for real axis/motors (eg. Motor type, encoder type)
dbLoadTemplate("Db/blc_motor_extras.substitutions")


#Load digital IO databases
#dbLoadTemplate("Db/galil_digital_ports.substitutions")
#Load analog IO databases
#dbLoadTemplate("Db/galil_analog_ports.substitutions")




# GalilCreateController command parameters are:
#
# 1. Const char *portName 	- The name of the asyn port that will be created for this controller
# 2. Const char *address 	- The address of the controller
# 3. double updatePeriod	- The time in ms between datarecords 8ms minimum.  Async if controller + bus supports it, otherwise is polled/synchronous.
#                       	- Specify negative updatePeriod < 0 to force synchronous tcp poll period.  Otherwise will try async udp mode first
# Create a Galil controller
GalilCreateController("Galil2183", "192.168.1.67", 18)



# GalilCreateAxis command parameters are:
#
# 1. char *portName Asyn port for controller
# 2. char  axis A-H,
# 3. int   limits_as_home (0 off 1 on), //LIU: switch_as_home (0= Encoder, 1= homeSwitch), 
# 4. char  *Motor interlock digital port number 1 to 8 eg. "1,2,4".  1st 8 bits are supported
# 5. int   Interlock switch type 0 normally open, all other values is normally closed interlock switch type
# Create the axis
GalilCreateAxis("Galil2183","A",1,"",0)
GalilCreateAxis("Galil2183","B",1,"",0)
GalilCreateAxis("Galil2183","C",1,"",0)
GalilCreateAxis("Galil2183","D",1,"",0)
GalilCreateAxis("Galil2183","E",1,"",0)
GalilCreateAxis("Galil2183","F",1,"",0)
GalilCreateAxis("Galil2183","G",1,"",0)
GalilCreateAxis("Galil2183","H",1,"",0)



# GalilCreateCSAxes command parameters are:
#
# 1. char *portName Asyn port for controller

#Create all CS axes (ie. I-P axis)
#GalilCreateCSAxes("Galil2183")

# GalilStartController command parameters are:
#
# 1. char *portName Asyn port for controller
# 2. char *code file(s) to deliver to the controller we are starting. "" = use generated code (recommended)
#             Specify a single file or to use templates use: headerfile;bodyfile1!bodyfile2!bodyfileN;footerfile
# 3. int   Burn program to EEPROM conditions
#             0 = transfer code if differs from eeprom, dont burn code to eeprom, then finally execute code thread 0.
#             1 = transfer code if differs from eeprom, burn code to eeprom, then finally execute code thread 0.
#             It is asssumed thread 0 starts all other required threads
# 4. int   display code. Set bit 1 to display generated code and or the code file specified.  Set bit 2 to display uploaded code
# 5. int   Thread mask.  Check these threads are running after controller code start.  Bit 0 = thread 0 and so on
#             if thread mask = 0 and GalilCreateAxis appears > 0 then threads 0 to number of GalilCreateAxis is checked (good when using the generated code)

# Start the controller
#  GalilStartController("Galil2183", "MyGalil.gmc", 1, 0, 0)

GalilStartController("Galil2183", "", 1, 0, 0)


# GalilCreateProfile command parameters are:
#
# 1. char *portName Asyn port for controller
# 2. Int maxPoints in trajectory

# Create trajectory profiles
#GalilCreateProfile("Galil2183", 2000)

