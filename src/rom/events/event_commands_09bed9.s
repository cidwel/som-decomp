; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BED9
.include "src/rom/event_command_macros.inc"
event_2D1_command_BED9:
    event_wait 0
