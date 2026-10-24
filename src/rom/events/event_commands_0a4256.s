; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4256
.include "src/rom/event_command_macros.inc"
event_4E7_command_4256:
    event_wait 0
