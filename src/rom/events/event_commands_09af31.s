; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AF31
.include "src/rom/event_command_macros.inc"
event_295_command_AF31:
    event_wait 0
