; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3418
.include "src/rom/event_command_macros.inc"
event_4E2_command_3418:
    event_wait 0
