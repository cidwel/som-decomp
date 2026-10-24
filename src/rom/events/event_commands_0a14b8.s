; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $14B8
.include "src/rom/event_command_macros.inc"
event_42D_command_14B8:
    event_wait 16
