; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8FDD
.include "src/rom/event_command_macros.inc"
event_204_command_8FDD:
    event_wait 0
