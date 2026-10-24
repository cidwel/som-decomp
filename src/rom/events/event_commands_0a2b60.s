; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2B60
.include "src/rom/event_command_macros.inc"
event_4E0_command_2B60:
    event_wait 0
