; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8E89
.include "src/rom/event_command_macros.inc"
event_203_command_8E89:
    event_wait 0
