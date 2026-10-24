; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8F27
.include "src/rom/event_command_macros.inc"
event_204_command_8F27:
    event_wait 0
