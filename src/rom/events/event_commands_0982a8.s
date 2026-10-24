; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $82A8
.include "src/rom/event_command_macros.inc"
event_1E5_command_82A8:
    event_wait 0
event_1E5_command_82AA:
    event_increment_flag 22
event_1E5_command_82AC:
    event_increment_flag 4
event_1E5_command_82AE:
    event_increment_flag 13
event_1E5_command_82B0:
    event_refresh_objects 
event_1E5_command_82B1:
    event_clone_actor 1
