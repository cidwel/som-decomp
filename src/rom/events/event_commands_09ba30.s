; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BA30
.include "src/rom/event_command_macros.inc"
event_2B6_command_BA30:
    event_jump 1535
event_2B6_command_BA32:
    event_end 
