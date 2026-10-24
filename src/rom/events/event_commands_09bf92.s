; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BF92
.include "src/rom/event_command_macros.inc"
event_2D2_command_BF92:
    event_actor_walk 128, 0, 63
event_2D2_command_BF95:
    event_wait_idle 
event_2D2_command_BF96:
    event_actor_walk 128, 0, 16
event_2D2_command_BF99:
    event_wait_idle 
event_2D2_command_BF9A:
    event_increment_flag 60
event_2D2_command_BF9C:
    event_refresh_objects 
event_2D2_command_BF9D:
    event_end 
