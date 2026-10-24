; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0CA8
.include "src/rom/event_command_macros.inc"
event_400_command_0CA8:
    event_change_map 206
event_400_command_0CAA:
    event_actor_walk 0, 0, 0
event_400_command_0CAD:
    event_wait_idle 
event_400_command_0CAE:
    event_actor_animation_loop 0, 139
event_400_command_0CB1:
    event_wait_idle 
