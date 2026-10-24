; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BFFE
.include "src/rom/event_command_macros.inc"
event_2D4_command_BFFE:
    event_wait 0
