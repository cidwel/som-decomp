; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3EA7
.include "src/rom/event_command_macros.inc"
event_137_command_3EA7:
    event_jump 1535
event_137_command_3EA9:
    event_end 
event_138_command_3EAA:
    event_test_flag_range 169, 2, 15
event_138_command_3EAD:
    event_jump 313
