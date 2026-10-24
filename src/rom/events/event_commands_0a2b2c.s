; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2B2C
.include "src/rom/event_command_macros.inc"
event_4E0_command_2B2C:
    event_wait 0
