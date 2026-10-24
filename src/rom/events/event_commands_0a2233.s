; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2233
.include "src/rom/event_command_macros.inc"
event_4B6_command_2233:
    event_gather 
event_4B6_command_2234:
    event_wait 32
