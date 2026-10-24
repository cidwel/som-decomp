; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $389B
.include "src/rom/event_command_macros.inc"
event_11D_command_389B:
    event_end 
event_11E_command_389C:
    event_test_flag_range 80, 0, 0
event_11E_command_389F:
    event_jump 0
event_11E_command_38A1:
    event_end 
event_11F_command_38A2:
    event_test_flag_range 17, 0, 10
event_11F_command_38A5:
    event_jump 0
event_11F_command_38A7:
    event_test_flag_range 46, 0, 0
event_11F_command_38AA:
    event_jump 1256
event_11F_command_38AC:
    event_end 
event_120_command_38AD:
    event_test_flag_range 17, 0, 0
event_120_command_38B0:
    event_jump 303
