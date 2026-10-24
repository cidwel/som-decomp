; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $474C
.include "src/rom/event_command_macros.inc"
event_14A_command_474C:
    event_test_flag_range 18, 4, 4
event_14A_command_474F:
    event_increment_flag 18
event_14A_command_4751:
    event_refresh_objects 
event_14A_command_4752:
    event_jump 1535
event_14A_command_4754:
    event_end 
