; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $530A
.include "src/rom/event_command_macros.inc"
event_172_command_530A:
    event_jump 1535
event_172_command_530C:
    event_end 
