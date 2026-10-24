; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $538A
.include "src/rom/event_command_macros.inc"
event_173_command_538A:
    event_wait 0
