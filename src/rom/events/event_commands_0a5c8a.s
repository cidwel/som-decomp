; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5C8A
.include "src/rom/event_command_macros.inc"
event_51D_command_5C8A:
    event_wait 0
