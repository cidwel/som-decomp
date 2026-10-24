; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F0DB
.include "src/rom/event_command_macros.inc"
event_3EC_command_F0DB:
    event_screen 0
event_3EC_command_F0DD:
    event_call 1924
event_3EC_command_F0DF:
    event_wait 1
event_3EC_command_F0E1:
    event_screen 1
