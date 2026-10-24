; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3AA9
.include "src/rom/event_command_macros.inc"
event_4E4_command_3AA9:
    event_wait_idle 
event_4E4_command_3AAA:
    event_wait 0
