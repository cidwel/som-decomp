; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $59BB
.include "src/rom/event_command_macros.inc"
event_50A_command_59BB:
    event_wait 0
