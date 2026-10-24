; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4798
.include "src/rom/event_command_macros.inc"
event_14B_command_4798:
    event_test_flag_range 18, 3, 3
event_14B_command_479B:
    event_increment_flag 18
event_14B_command_479D:
    event_refresh_objects 
event_14B_command_479E:
    event_jump 1535
event_14B_command_47A0:
    event_end 
