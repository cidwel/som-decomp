; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7CF8
.include "src/rom/event_command_macros.inc"
event_1D9_command_7CF8:
    event_jump 1535
event_1D9_command_7CFA:
    event_end 
event_1DA_command_7CFB:
    event_test_actor_field 2, 5, 128, 233
event_1DA_command_7CFF:
    event_jump 473
event_1DA_command_7D01:
    event_test_actor_field 2, 6, 128, 233
event_1DA_command_7D05:
    event_jump 473
event_1DA_command_7D07:
    event_test_actor 2
event_1DA_command_7D09:
    event_jump 486
event_1DA_command_7D0B:
    event_freeze 
event_1DA_command_7D0C:
    event_gather 
event_1DA_command_7D0D:
    event_screen 8
event_1DA_command_7D0F:
    event_test_flag_range 4, 1, 15
event_1DA_command_7D12:
    event_jump 485
