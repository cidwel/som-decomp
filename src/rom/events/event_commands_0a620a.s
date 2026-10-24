; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $620A
.include "src/rom/event_command_macros.inc"
event_532_command_620A:
    event_wait 0
