####################################################
## save_restore setup
save_restoreSet_Debug(0)

# status-PV prefix, so save_restore can find its status PV's.
save_restoreSet_status_prefix("blc:")

# Ok to save/restore save sets with missing values (no CA connection to PV)?  
save_restoreSet_IncompleteSetsOk(1)
# Save dated backup files?
save_restoreSet_DatedBackupFiles(1)

# Number of sequenced backup files to write
save_restoreSet_NumSeqFiles(1)
# Time interval between sequenced backups
save_restoreSet_SeqPeriodInSeconds(300)

# specify where save files should be
#set_savefile_path(${TOP}, "autosaveSaves")
set_savefile_path("${TOP}/iocBoot/${IOC}/autosave", "")

# specify what save files should be restored.  Note these files must be
# in the directory specified in set_savefile_path(), or, if that function
# has not been called, from the directory current when iocInit is invoked
# example: set_pass0_restoreFile("autosave_geiger.sav")

# specify directories in which to to search for included request files
# set_requestfile_path(${TOP}, "autosaveReqs")
set_requestfile_path("${GALIL}/GalilSup/Db", "")
set_requestfile_path("${MOTOR}/motorApp/Db", "")
set_requestfile_path("${TOP}/iocBoot/${IOC}/req", "")

#dbLoadRecords("$(AUTOSAVE)/asApp/Db/save_restoreStatus.db","P=")

save_restoreSet_CAReconnect(1)

# restore positions at pass 0 so motors don't move
set_pass0_restoreFile("positions.sav")
set_pass1_restoreFile("blcg_motor_extras1.sav")
set_pass1_restoreFile("blcg_motor_extras2.sav")
set_pass1_restoreFile("blcg_motor_extras3.sav")
set_pass1_restoreFile("blcg_motor_extras4.sav")
set_pass1_restoreFile("blcg_motor_extras5.sav")
set_pass1_restoreFile("blcg_motor_extras6.sav")
set_pass1_restoreFile("blcg_motor_extras7.sav")
set_pass1_restoreFile("blcg_motor_extras8.sav")
# restore settings at pass 0

## End of autosave set-up
####################################################
