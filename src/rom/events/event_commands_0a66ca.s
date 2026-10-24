; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $66CA
.include "src/rom/event_command_macros.inc"
event_558_command_66CA:
    event_wait 0
