; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8A74
.include "src/rom/event_command_macros.inc"
event_1F6_command_8A74:
    event_actor_walk 1, 1, 0
event_1F6_command_8A77:
    event_actor_walk 2, 0, 0
event_1F6_command_8A7A:
    event_actor_walk 3, 0, 0
event_1F6_command_8A7D:
    event_wait_idle 
