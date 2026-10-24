; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $78C0
.include "src/rom/event_command_macros.inc"
event_1CF_command_78C0:
    event_wait 0
