; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2E14
.include "src/rom/event_command_macros.inc"
event_4E1_command_2E14:
    event_wait 8
