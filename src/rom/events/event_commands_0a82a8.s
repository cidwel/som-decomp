; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $82A8
.include "src/rom/event_command_macros.inc"
event_5F8_command_82A8:
    event_wait 32
event_5F8_command_82AA:
    event_wait 0
