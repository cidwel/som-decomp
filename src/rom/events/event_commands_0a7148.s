; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7148
.include "src/rom/event_command_macros.inc"
event_586_command_7148:
    event_call 1993
event_586_command_714A:
    event_end 
event_587_command_714B:
    event_screen_word 6, 16912
event_587_command_714F:
    event_call 1152
event_587_command_7151:
    event_wait 16
