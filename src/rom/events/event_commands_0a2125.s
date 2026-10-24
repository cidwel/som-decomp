; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2125
.include "src/rom/event_command_macros.inc"
event_4B3_command_2125:
    event_wait 0
