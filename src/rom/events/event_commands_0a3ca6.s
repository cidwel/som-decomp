; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3CA6
.include "src/rom/event_command_macros.inc"
event_4E5_command_3CA6:
    event_wait_idle 
event_4E5_command_3CA7:
    event_wait 0
