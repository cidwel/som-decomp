; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C4CD
.include "src/rom/event_command_macros.inc"
event_2DC_command_C4CD:
    event_jump 1535
event_2DC_command_C4CF:
    event_end 
