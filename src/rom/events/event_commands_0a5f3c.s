; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5F3C
.include "src/rom/event_command_macros.inc"
event_52E_command_5F3C:
    event_increment_flag 53
event_52E_command_5F3E:
    event_refresh_objects 
