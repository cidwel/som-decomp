; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2A3E
.include "src/rom/event_command_macros.inc"
event_4E0_command_2A3E:
    event_wait 0
