#!../../bin/linux-x86_64/sm

#- You may have to change sm to something else
#- everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/sm.dbd"
sm_registerRecordDeviceDriver pdbbase


cd "${TOP}/iocBoot/${IOC}"

# Configure an example controller

< galil-controller.cmd
< autosave.cmd

iocInit
#set the hard limit protection function to be disabled
dbpf("m1_WLP_CMD","0")
dbpf("m2_WLP_CMD","0")
dbpf("m3_WLP_CMD","0")
dbpf("m4_WLP_CMD","0")
dbpf("m5_WLP_CMD","0")
dbpf("m6_WLP_CMD","0")
dbpf("m7_WLP_CMD","0")
dbpf("m8_WLP_CMD","0")


# Save motor positions every 5 seconds
create_monitor_set("positions.req", 	     5, "" )
create_monitor_set("blcg_motor_extras1.req", 30,"P=m,M=1")
create_monitor_set("blcg_motor_extras2.req", 30,"P=m,M=2")
create_monitor_set("blcg_motor_extras3.req", 30,"P=m,M=3")
create_monitor_set("blcg_motor_extras4.req", 30,"P=m,M=4")
create_monitor_set("blcg_motor_extras5.req", 30,"P=m,M=5")
create_monitor_set("blcg_motor_extras6.req", 30,"P=m,M=6")
create_monitor_set("blcg_motor_extras7.req", 30,"P=m,M=7")
create_monitor_set("blcg_motor_extras8.req", 30,"P=m,M=8")
create_monitor_set("blcg_ctrl_extras.req",  30,"P=m")





##let the ioc run in the backend:
# screen -dmS Galil ./start-Galil-Motor.sh
