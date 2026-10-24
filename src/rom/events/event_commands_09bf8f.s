; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BF8F
.include "src/rom/event_command_macros.inc"
event_2D2_command_BF8F:
    event_wait 0
