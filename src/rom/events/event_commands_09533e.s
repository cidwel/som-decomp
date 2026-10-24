; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $533E
.include "src/rom/event_command_macros.inc"
event_173_command_533E:
    event_wait 0
