; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $32F4
.include "src/rom/event_command_macros.inc"
event_4E2_command_32F4:
    event_wait 0
