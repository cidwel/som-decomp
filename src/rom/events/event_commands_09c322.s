; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C322
.include "src/rom/event_command_macros.inc"
event_2D6_command_C322:
    event_actor_walk 128, 2, 16
event_2D6_command_C325:
    event_wait_idle 
event_2D6_command_C326:
    event_actor_walk 128, 1, 0
event_2D6_command_C329:
    event_wait_idle 
event_2D6_command_C32A:
    event_call 83
event_2D6_command_C32C:
    event_actor_animation_loop 128, 129
event_2D6_command_C32F:
    event_wait_idle 
event_2D6_command_C330:
    event_wait 48
event_2D6_command_C332:
    event_increment_flag 60
event_2D6_command_C334:
    event_refresh_objects 
event_2D6_command_C335:
    event_end 
