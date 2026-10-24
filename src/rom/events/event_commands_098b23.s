; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8B23
.include "src/rom/event_command_macros.inc"
event_1F6_command_8B23:
    event_wait 0
