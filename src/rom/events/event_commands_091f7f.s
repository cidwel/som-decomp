; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1F7F
.include "src/rom/event_command_macros.inc"
event_0E5_command_1F7F:
    event_wait 0
