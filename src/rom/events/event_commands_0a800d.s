; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $800D
.include "src/rom/event_command_macros.inc"
event_5F8_command_800D:
    event_wait 0
