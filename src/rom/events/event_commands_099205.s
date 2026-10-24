; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9205
.include "src/rom/event_command_macros.inc"
event_20A_command_9205:
    event_wait 0
