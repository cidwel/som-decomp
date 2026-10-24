; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $54D3
.include "src/rom/event_command_macros.inc"
event_173_command_54D3:
    event_wait 0
