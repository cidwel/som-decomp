; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $899D
.include "src/rom/event_command_macros.inc"
event_1F5_command_899D:
    event_wait 0
