; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $102C
.include "src/rom/event_command_macros.inc"
event_041_command_102C:
    event_wait 0
event_041_command_102E:
    event_increment_flag 14
event_041_command_1030:
    event_set_flag 20, 6
event_041_command_1033:
    event_increment_flag 21
event_041_command_1035:
    event_refresh_objects 
event_041_command_1036:
    event_clone_actor 2
event_041_command_1038:
    event_audio_request 1, 53, 15, 255
