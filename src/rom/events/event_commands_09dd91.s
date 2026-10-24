; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DD91
.include "src/rom/event_command_macros.inc"
event_397_command_DD91:
    event_wait 0
