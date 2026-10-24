; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8320
.include "src/rom/event_command_macros.inc"
event_5F8_command_8320:
    event_wait_idle 
event_5F8_command_8321:
    event_wait 0
