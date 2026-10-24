; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8B22
.include "src/rom/event_command_macros.inc"
event_66D_command_8B22:
    event_increment_flag 38
event_66D_command_8B24:
    event_refresh_objects 
event_66D_command_8B25:
    event_actor_walk 5, 0, 63
event_66D_command_8B28:
    event_actor_walk 6, 0, 63
