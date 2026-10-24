; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $31D8
.include "src/rom/event_command_macros.inc"
event_4E2_command_31D8:
    event_gather 
event_4E2_command_31D9:
    event_screen 8
event_4E2_command_31DB:
    event_actor_walk 1, 3, 24
event_4E2_command_31DE:
    event_actor_walk 2, 3, 12
event_4E2_command_31E1:
    event_wait_idle 
event_4E2_command_31E2:
    event_actor_walk 1, 2, 0
event_4E2_command_31E5:
    event_actor_walk 2, 2, 0
event_4E2_command_31E8:
    event_actor_walk 3, 2, 0
event_4E2_command_31EB:
    event_wait_idle 
