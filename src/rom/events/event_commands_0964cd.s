; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $64CD
.include "src/rom/event_command_macros.inc"
event_1A7_command_64CD:
    event_jump 1535
event_1A7_command_64CF:
    event_end 
event_1A8_command_64D0:
    event_end 
event_1A9_command_64D1:
    event_end 
event_1AA_command_64D2:
    event_end 
event_1AB_command_64D3:
    event_end 
event_1AC_command_64D4:
    event_test_flag_range 96, 1, 15
event_1AC_command_64D7:
    event_jump 0
event_1AC_command_64D9:
    event_call 1937
event_1AC_command_64DB:
    event_call 447
event_1AC_command_64DD:
    event_call 1932
event_1AC_command_64DF:
    event_call 1951
event_1AC_command_64E1:
    event_end 
event_1AD_command_64E2:
    event_test_flag_range 96, 4, 15
event_1AD_command_64E5:
    event_jump 0
event_1AD_command_64E7:
    event_call 1937
event_1AD_command_64E9:
    event_call 447
event_1AD_command_64EB:
    event_call 1944
event_1AD_command_64ED:
    event_call 447
event_1AD_command_64EF:
    event_call 1944
event_1AD_command_64F1:
    event_call 447
event_1AD_command_64F3:
    event_set_flag 96, 7
event_1AD_command_64F6:
    event_end 
event_1AE_command_64F7:
    event_test_flag_range 21, 5, 5
event_1AE_command_64FA:
    event_jump 0
event_1AE_command_64FC:
    event_test_flag_range 96, 7, 15
event_1AE_command_64FF:
    event_jump 0
event_1AE_command_6501:
    event_call 447
event_1AE_command_6503:
    event_call 447
event_1AE_command_6505:
    event_call 447
event_1AE_command_6507:
    event_end 
event_1AF_command_6508:
    event_call 7
event_1AF_command_650A:
    event_test_flag_range 97, 1, 1
event_1AF_command_650D:
    event_jump 428
event_1AF_command_650F:
    event_test_flag_range 97, 2, 2
event_1AF_command_6512:
    event_jump 429
event_1AF_command_6514:
    event_test_flag_range 97, 3, 3
event_1AF_command_6517:
    event_jump 430
event_1AF_command_6519:
    event_test_flag_range 97, 4, 4
event_1AF_command_651C:
    event_jump 570
event_1AF_command_651E:
    event_end 
event_1B0_command_651F:
    event_freeze 
event_1B0_command_6520:
    event_gather 
event_1B0_command_6521:
    event_screen 8
event_1B0_command_6523:
    event_test_flag_range 20, 1, 1
event_1B0_command_6526:
    event_jump 435
event_1B0_command_6528:
    event_test_flag_range 20, 2, 4
event_1B0_command_652B:
    event_jump 436
event_1B0_command_652D:
    event_test_flag_range 20, 5, 6
event_1B0_command_6530:
    event_jump 437
event_1B0_command_6532:
    event_test_flag_range 20, 7, 14
event_1B0_command_6535:
    event_jump 439
