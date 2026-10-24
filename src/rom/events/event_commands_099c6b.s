; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9C6B
.include "src/rom/event_command_macros.inc"
event_236_command_9C6B:
    event_increment_flag 24
event_236_command_9C6D:
    event_refresh_objects 
event_236_command_9C6E:
    event_wait 16
