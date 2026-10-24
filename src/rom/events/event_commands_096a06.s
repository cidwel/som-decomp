; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6A06
.include "src/rom/event_command_macros.inc"
event_1B5_command_6A06:
    event_wait 0
