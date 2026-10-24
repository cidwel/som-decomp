; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2F4B
.include "src/rom/event_command_macros.inc"
event_4E1_command_2F4B:
    event_wait 0
