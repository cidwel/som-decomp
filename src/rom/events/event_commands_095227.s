; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5227
.include "src/rom/event_command_macros.inc"
event_16E_command_5227:
    event_call 1940
event_16E_command_5229:
    event_increment_flag 26
event_16E_command_522B:
    event_refresh_objects 
