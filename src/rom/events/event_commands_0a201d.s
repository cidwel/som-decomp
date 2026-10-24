; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $201D
.include "src/rom/event_command_macros.inc"
event_4B3_command_201D:
    event_actor_walk 4, 3, 0
event_4B3_command_2020:
    event_actor_walk 5, 3, 0
event_4B3_command_2023:
    event_wait_idle 
event_4B3_command_2024:
    event_actor_animation_loop 4, 1
event_4B3_command_2027:
    event_actor_animation_loop 5, 1
event_4B3_command_202A:
    event_wait_idle 
event_4B3_command_202B:
    event_wait 32
event_4B3_command_202D:
    event_actor_walk 6, 1, 16
event_4B3_command_2030:
    event_wait_idle 
