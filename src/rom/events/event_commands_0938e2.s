; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $38E2
.include "src/rom/event_command_macros.inc"
event_120_command_38E2:
    event_wait 0
