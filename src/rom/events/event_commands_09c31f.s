; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C31F
.include "src/rom/event_command_macros.inc"
event_2D6_command_C31F:
    event_wait 0
