; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1A46
.include "src/rom/event_command_macros.inc"
event_4A3_command_1A46:
    event_wait 0
