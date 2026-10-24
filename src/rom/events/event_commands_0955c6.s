; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $55C6
.include "src/rom/event_command_macros.inc"
event_17F_command_55C6:
    event_wait 0
