; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $17BD
.include "src/rom/event_command_macros.inc"
event_0B4_command_17BD:
    event_jump 1535
event_0B4_command_17BF:
    event_end 
