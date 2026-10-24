; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $669B
.include "src/rom/event_command_macros.inc"
event_558_command_669B:
    event_wait 0
