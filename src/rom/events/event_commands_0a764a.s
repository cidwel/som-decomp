; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $764A
.include "src/rom/event_command_macros.inc"
event_59B_command_764A:
    event_wait 0
