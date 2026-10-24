; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0F90
.include "src/rom/event_command_macros.inc"
event_040_command_0F90:
    event_wait 0
event_040_command_0F92:
    event_increment_flag 13
event_040_command_0F94:
    event_refresh_objects 
event_040_command_0F95:
    event_clone_actor 1
event_040_command_0F97:
    event_audio_request 1, 53, 15, 255
