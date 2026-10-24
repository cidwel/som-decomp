; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3E12
.include "src/rom/event_command_macros.inc"
event_136_command_3E12:
    event_wait 0
