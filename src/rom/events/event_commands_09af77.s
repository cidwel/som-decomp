; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AF77
.include "src/rom/event_command_macros.inc"
event_295_command_AF77:
    event_wait 0
