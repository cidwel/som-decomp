; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AA71
.include "src/rom/event_command_macros.inc"
event_28B_command_AA71:
    event_wait 0
