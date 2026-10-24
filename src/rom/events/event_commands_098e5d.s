; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8E5D
.include "src/rom/event_command_macros.inc"
event_203_command_8E5D:
    event_wait 0
