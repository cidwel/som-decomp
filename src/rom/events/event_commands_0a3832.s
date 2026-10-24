; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3832
.include "src/rom/event_command_macros.inc"
event_4E3_command_3832:
    event_wait 0
