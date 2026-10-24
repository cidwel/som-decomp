; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1067
.include "src/rom/event_command_macros.inc"
event_042_command_1067:
    event_wait 0
event_042_command_1069:
    event_increment_flag 14
event_042_command_106B:
    event_set_flag 20, 6
event_042_command_106E:
    event_increment_flag 21
event_042_command_1070:
    event_refresh_objects 
event_042_command_1071:
    event_clone_actor 2
event_042_command_1073:
    event_audio_request 1, 53, 15, 255
