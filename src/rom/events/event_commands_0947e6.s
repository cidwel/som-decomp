; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $47E6
.include "src/rom/event_command_macros.inc"
event_14C_command_47E6:
    event_test_flag_range 19, 0, 0
event_14C_command_47E9:
    event_increment_flag 19
event_14C_command_47EB:
    event_jump 1535
event_14C_command_47ED:
    event_end 
event_14D_command_47EE:
    event_test_flag_range 18, 6, 15
event_14D_command_47F1:
    event_jump 348
