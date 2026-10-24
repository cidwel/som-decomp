; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $ABB4
.include "src/rom/event_command_macros.inc"
event_28B_command_ABB4:
    event_wait 0
