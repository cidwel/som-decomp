; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F189
.include "src/rom/event_command_macros.inc"
event_3ED_command_F189:
    event_wait 0
event_3ED_command_F18B:
    event_call 1951
