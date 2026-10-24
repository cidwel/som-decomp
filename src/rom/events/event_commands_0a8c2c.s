; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8C2C
.include "src/rom/event_command_macros.inc"
event_66D_command_8C2C:
    event_wait 0
