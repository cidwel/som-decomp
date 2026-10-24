; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $09A3
.include "src/rom/event_command_macros.inc"
event_01F_command_09A3:
    event_return 
event_01F_command_09A4:
    event_end 
event_020_command_09A5:
    event_call 31
