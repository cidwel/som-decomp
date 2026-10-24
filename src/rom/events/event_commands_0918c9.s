; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $18C9
.include "src/rom/event_command_macros.inc"
event_0B8_command_18C9:
    event_wait 0
