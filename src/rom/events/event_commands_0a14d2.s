; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $14D2
.include "src/rom/event_command_macros.inc"
event_42D_command_14D2:
    event_wait 0
