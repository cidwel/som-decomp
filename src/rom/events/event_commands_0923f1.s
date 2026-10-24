; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $23F1
.include "src/rom/event_command_macros.inc"
event_0FB_command_23F1:
    event_wait 0
