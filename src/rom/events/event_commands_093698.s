; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3698
.include "src/rom/event_command_macros.inc"
event_114_command_3698:
    event_wait 0
