; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $90C5
.include "src/rom/event_command_macros.inc"
event_204_command_90C5:
    event_wait 0
