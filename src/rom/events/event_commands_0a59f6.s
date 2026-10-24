; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $59F6
.include "src/rom/event_command_macros.inc"
event_511_command_59F6:
    event_wait 16
