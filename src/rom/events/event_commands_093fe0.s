; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3FE0
.include "src/rom/event_command_macros.inc"
event_139_command_3FE0:
    event_wait 0
