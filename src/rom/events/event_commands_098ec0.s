; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8EC0
.include "src/rom/event_command_macros.inc"
event_203_command_8EC0:
    event_wait 0
