; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2A7E
.include "src/rom/event_command_macros.inc"
event_106_command_2A7E:
    event_wait_idle 
event_106_command_2A7F:
    event_wait 0
