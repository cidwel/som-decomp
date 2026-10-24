; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AB31
.include "src/rom/event_command_macros.inc"
event_28B_command_AB31:
    event_wait 0
