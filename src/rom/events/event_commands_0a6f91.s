; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6F91
.include "src/rom/event_command_macros.inc"
event_583_command_6F91:
    event_set_flag 171, 2
event_583_command_6F94:
    event_audio_request 1, 8, 27, 143
event_583_command_6F99:
    event_return 
event_583_command_6F9A:
    event_end 
event_584_command_6F9B:
    event_set_actor_field 2, 204, 56
event_584_command_6F9F:
    event_set_actor_field 3, 204, 7
