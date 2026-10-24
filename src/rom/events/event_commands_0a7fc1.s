; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7FC1
.include "src/rom/event_command_macros.inc"
event_5F8_command_7FC1:
    event_wait 0
