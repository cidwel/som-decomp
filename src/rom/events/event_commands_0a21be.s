; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $21BE
.include "src/rom/event_command_macros.inc"
event_4B4_command_21BE:
    event_wait 8
