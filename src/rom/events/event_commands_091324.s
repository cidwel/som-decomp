; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1324
.include "src/rom/event_command_macros.inc"
event_081_command_1324:
    event_wait 0
