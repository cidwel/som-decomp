; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $43FE
.include "src/rom/event_command_macros.inc"
event_4E8_command_43FE:
    event_actor_walk 5, 3, 40
event_4E8_command_4401:
    event_actor_walk 6, 2, 40
event_4E8_command_4404:
    event_wait_idle 
event_4E8_command_4405:
    event_actor_walk 4, 3, 16
event_4E8_command_4408:
    event_actor_walk 5, 1, 56
event_4E8_command_440B:
    event_actor_walk 6, 1, 56
event_4E8_command_440E:
    event_wait_idle 
event_4E8_command_440F:
    event_actor_walk 4, 3, 56
event_4E8_command_4412:
    event_actor_walk 5, 1, 56
event_4E8_command_4415:
    event_actor_walk 6, 1, 56
event_4E8_command_4418:
    event_wait_idle 
event_4E8_command_4419:
    event_actor_walk 4, 1, 0
event_4E8_command_441C:
    event_wait_idle 
event_4E8_command_441D:
    event_actor_animation_loop 4, 157
event_4E8_command_4420:
    event_wait_idle 
event_4E8_command_4421:
    event_wait 16
event_4E8_command_4423:
    event_actor_animation 4, 139
event_4E8_command_4426:
    event_wait_idle 
event_4E8_command_4427:
    event_actor_animation_loop 4, 157
event_4E8_command_442A:
    event_wait_idle 
event_4E8_command_442B:
    event_wait 8
