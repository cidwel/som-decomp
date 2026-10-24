; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AF49
.include "src/rom/event_command_macros.inc"
event_295_command_AF49:
    event_wait 0
