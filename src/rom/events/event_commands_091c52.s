; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1C52
.include "src/rom/event_command_macros.inc"
event_0D2_command_1C52:
    event_wait 0
