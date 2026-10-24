; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5FE9
.include "src/rom/event_command_macros.inc"
event_52F_command_5FE9:
    event_call 1832
event_52F_command_5FEB:
    event_increment_flag 53
event_52F_command_5FED:
    event_refresh_objects 
