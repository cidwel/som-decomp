; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0FE6
.include "src/rom/event_command_macros.inc"
event_041_command_0FE6:
    event_wait 0
