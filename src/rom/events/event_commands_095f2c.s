; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5F2C
.include "src/rom/event_command_macros.inc"
event_193_command_5F2C:
    event_wait 0
