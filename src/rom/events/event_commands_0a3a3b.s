; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3A3B
.include "src/rom/event_command_macros.inc"
event_4E4_command_3A3B:
    event_wait 0
