; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $234A
.include "src/rom/event_command_macros.inc"
event_0F8_command_234A:
    event_wait 0
