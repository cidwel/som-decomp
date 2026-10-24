; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DD5C
.include "src/rom/event_command_macros.inc"
event_397_command_DD5C:
    event_wait 0
