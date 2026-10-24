; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7665
.include "src/rom/event_command_macros.inc"
event_1CE_command_7665:
    event_increment_flag 21
event_1CE_command_7667:
    event_refresh_objects 
event_1CE_command_7668:
    event_wait 16
