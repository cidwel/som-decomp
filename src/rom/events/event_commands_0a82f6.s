; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $82F6
.include "src/rom/event_command_macros.inc"
event_5F8_command_82F6:
    event_screen 7
event_5F8_command_82F8:
    event_wait 0
