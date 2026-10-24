; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $411D
.include "src/rom/event_command_macros.inc"
event_13A_command_411D:
    event_wait 0
