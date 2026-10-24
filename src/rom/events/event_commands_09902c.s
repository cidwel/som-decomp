; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $902C
.include "src/rom/event_command_macros.inc"
event_204_command_902C:
    event_wait 0
