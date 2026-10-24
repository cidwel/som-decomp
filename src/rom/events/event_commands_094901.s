; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4901
.include "src/rom/event_command_macros.inc"
event_153_command_4901:
    event_jump 1535
event_153_command_4903:
    event_end 
