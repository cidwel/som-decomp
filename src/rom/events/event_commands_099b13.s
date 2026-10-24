; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9B13
.include "src/rom/event_command_macros.inc"
event_22E_command_9B13:
    event_increment_flag 168
event_22E_command_9B15:
    event_refresh_objects 
event_22E_command_9B16:
    event_increment_flag 24
event_22E_command_9B18:
    event_jump 1408
event_22E_command_9B1A:
    event_end 
