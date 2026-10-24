; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1F05
.include "src/rom/event_command_macros.inc"
event_4B3_command_1F05:
    event_wait_idle 
event_4B3_command_1F06:
    event_wait 0
