; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $49CB
.include "src/rom/event_command_macros.inc"
event_4EA_command_49CB:
    event_wait 0
