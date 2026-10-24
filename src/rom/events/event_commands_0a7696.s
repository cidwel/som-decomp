; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7696
.include "src/rom/event_command_macros.inc"
event_59B_command_7696:
    event_actor_walk 4, 0, 0
event_59B_command_7699:
    event_actor_walk 5, 3, 0
event_59B_command_769C:
    event_wait_idle 
event_59B_command_769D:
    event_actor_animation_loop 4, 129
event_59B_command_76A0:
    event_actor_walk 6, 3, 16
event_59B_command_76A3:
    event_wait_idle 
event_59B_command_76A4:
    event_actor_walk 6, 0, 0
event_59B_command_76A7:
    event_wait_idle 
event_59B_command_76A8:
    event_actor_animation_loop 6, 129
event_59B_command_76AB:
    event_wait_idle 
event_59B_command_76AC:
    event_wait 32
event_59B_command_76AE:
    event_actor_walk 5, 0, 0
event_59B_command_76B1:
    event_wait_idle 
