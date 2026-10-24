; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $770A
.include "src/rom/event_command_macros.inc"
event_1CE_command_770A:
    event_increment_flag 21
event_1CE_command_770C:
    event_refresh_objects 
event_1CE_command_770D:
    event_wait 8
