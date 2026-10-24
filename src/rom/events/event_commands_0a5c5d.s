; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5C5D
.include "src/rom/event_command_macros.inc"
event_51D_command_5C5D:
    event_wait_idle 
event_51D_command_5C5E:
    event_wait 0
