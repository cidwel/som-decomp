; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2251
.include "src/rom/event_command_macros.inc"
event_4B6_command_2251:
    event_wait 32
event_4B6_command_2253:
    event_set_flag 175, 1
event_4B6_command_2256:
    event_refresh_objects 
