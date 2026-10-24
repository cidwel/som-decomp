; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $19E1
.include "src/rom/event_command_macros.inc"
event_4A2_command_19E1:
    event_wait 0
