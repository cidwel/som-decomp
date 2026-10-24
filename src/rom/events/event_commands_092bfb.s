; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2BFB
.include "src/rom/event_command_macros.inc"
event_109_command_2BFB:
    event_end 
event_10A_command_2BFC:
    event_test_flag_range 16, 10, 15
event_10A_command_2BFF:
    event_jump 278
