; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $92DB
.include "src/rom/event_command_macros.inc"
event_20A_command_92DB:
    event_wait 0
