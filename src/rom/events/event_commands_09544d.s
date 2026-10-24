; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $544D
.include "src/rom/event_command_macros.inc"
event_173_command_544D:
    event_wait 0
