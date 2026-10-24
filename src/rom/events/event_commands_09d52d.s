; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D52D
.include "src/rom/event_command_macros.inc"
event_36F_command_D52D:
    event_actor_walk 6, 1, 24
event_36F_command_D530:
    event_actor_walk 1, 1, 4
event_36F_command_D533:
    event_actor_walk 2, 1, 4
event_36F_command_D536:
    event_actor_walk 3, 1, 4
event_36F_command_D539:
    event_wait_idle 
event_36F_command_D53A:
    event_call 82
