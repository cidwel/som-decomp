; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7440
.include "src/rom/event_command_macros.inc"
event_592_command_7440:
    event_wait 0
