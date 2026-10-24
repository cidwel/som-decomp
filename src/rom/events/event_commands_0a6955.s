; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6955
.include "src/rom/event_command_macros.inc"
event_55E_command_6955:
    event_wait 32
event_55E_command_6957:
    event_increment_flag 58
event_55E_command_6959:
    event_refresh_objects 
event_55E_command_695A:
    event_actor_walk 5, 0, 63
event_55E_command_695D:
    event_actor_walk 6, 0, 63
event_55E_command_6960:
    event_wait_idle 
