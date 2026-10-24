; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $180A
.include "src/rom/event_command_macros.inc"
event_4A1_command_180A:
    event_wait 0
