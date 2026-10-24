; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A9F5
.include "src/rom/event_command_macros.inc"
event_28A_command_A9F5:
    event_test_flag_range 54, 1, 1
event_28A_command_A9F8:
    event_increment_flag 54
event_28A_command_A9FA:
    event_end 
event_28B_command_A9FB:
    event_increment_flag 40
event_28B_command_A9FD:
    event_change_map 419
event_28B_command_A9FF:
    event_call 1994
event_28B_command_AA01:
    event_call 1151
