; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $29C6
.include "src/rom/event_command_macros.inc"
event_4E0_command_29C6:
    event_wait 0
