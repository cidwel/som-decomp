; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2776
.include "src/rom/event_command_macros.inc"
event_103_command_2776:
    event_wait 16
