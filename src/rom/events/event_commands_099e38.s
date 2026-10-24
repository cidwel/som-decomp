; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9E38
.include "src/rom/event_command_macros.inc"
event_23F_command_9E38:
    event_wait 0
