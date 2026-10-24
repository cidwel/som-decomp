; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6177
.include "src/rom/event_command_macros.inc"
event_532_command_6177:
    event_wait 0
