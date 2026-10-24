; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D8E0
.include "src/rom/event_command_macros.inc"
event_37E_command_D8E0:
    event_jump 1535
event_37E_command_D8E2:
    event_end 
event_37F_command_D8E3:
    event_change_map 333
event_37F_command_D8E5:
    event_jump 1796
event_37F_command_D8E7:
    event_end 
event_380_command_D8E8:
    event_test_flag_range 38, 0, 1
event_380_command_D8EB:
    event_jump 895
event_380_command_D8ED:
    event_test_flag_range 39, 3, 15
event_380_command_D8F0:
    event_jump 899
event_380_command_D8F2:
    event_change_map 532
event_380_command_D8F4:
    event_jump 1824
event_380_command_D8F6:
    event_end 
event_381_command_D8F7:
    event_call 1285
event_381_command_D8F9:
    event_set_flag 38, 2
event_381_command_D8FC:
    event_change_map 532
event_381_command_D8FE:
    event_jump 1824
event_381_command_D900:
    event_end 
event_382_command_D901:
    event_test_flag_range 39, 3, 15
event_382_command_D904:
    event_jump 907
event_382_command_D906:
    event_change_map 529
event_382_command_D908:
    event_jump 1824
event_382_command_D90A:
    event_end 
event_383_command_D90B:
    event_change_map 325
event_383_command_D90D:
    event_jump 1828
event_383_command_D90F:
    event_end 
event_384_command_D910:
    event_freeze 
event_384_command_D911:
    event_gather 
