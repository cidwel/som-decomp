; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2F00
.include "src/rom/event_command_macros.inc"
event_4E1_command_2F00:
    event_wait 8
