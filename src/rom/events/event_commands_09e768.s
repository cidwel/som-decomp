; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E768
.include "src/rom/event_command_macros.inc"
event_3C4_command_E768:
    event_jump 1535
event_3C4_command_E76A:
    event_end 
