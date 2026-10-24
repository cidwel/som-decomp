; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3EE9
.include "src/rom/event_command_macros.inc"
event_4E6_command_3EE9:
    event_actor_walk 4, 1, 0
event_4E6_command_3EEC:
    event_actor_walk 5, 1, 0
event_4E6_command_3EEF:
    event_actor_walk 6, 1, 0
event_4E6_command_3EF2:
    event_actor_walk 7, 1, 0
event_4E6_command_3EF5:
    event_wait_idle 
event_4E6_command_3EF6:
    event_wait 8
event_4E6_command_3EF8:
    event_actor_walk 0, 3, 16
event_4E6_command_3EFB:
    event_wait_idle 
event_4E6_command_3EFC:
    event_actor_walk 0, 0, 20
event_4E6_command_3EFF:
    event_actor_walk 4, 3, 0
event_4E6_command_3F02:
    event_actor_walk 5, 3, 0
event_4E6_command_3F05:
    event_actor_walk 7, 3, 0
event_4E6_command_3F08:
    event_wait_idle 
event_4E6_command_3F09:
    event_actor_walk 0, 2, 0
event_4E6_command_3F0C:
    event_actor_walk 8, 3, 0
event_4E6_command_3F0F:
    event_screen 8
