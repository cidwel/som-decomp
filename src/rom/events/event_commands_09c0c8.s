; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C0C8
.include "src/rom/event_command_macros.inc"
event_2D4_command_C0C8:
    event_increment_flag 60
event_2D4_command_C0CA:
    event_refresh_objects 
