; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $19B8
.include "src/rom/event_command_macros.inc"
event_0BC_command_19B8:
    event_jump 574
event_0BC_command_19BA:
    event_end 
