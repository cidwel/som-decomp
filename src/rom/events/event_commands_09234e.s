; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $234E
.include "src/rom/event_command_macros.inc"
event_0F8_command_234E:
    event_end 
