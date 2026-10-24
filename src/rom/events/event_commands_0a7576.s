; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7576
.include "src/rom/event_command_macros.inc"
event_592_command_7576:
    event_increment_flag 24
event_592_command_7578:
    event_end 
event_593_command_7579:
    event_freeze 
event_593_command_757A:
    event_gather 
event_593_command_757B:
    event_wait 32
