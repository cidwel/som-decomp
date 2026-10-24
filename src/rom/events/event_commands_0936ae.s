; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $36AE
.include "src/rom/event_command_macros.inc"
event_114_command_36AE:
    event_wait 0
