; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7A1D
.include "src/rom/event_command_macros.inc"
event_5F8_command_7A1D:
    event_actor_walk 4, 3, 0
event_5F8_command_7A20:
    event_actor_walk 5, 2, 0
event_5F8_command_7A23:
    event_actor_walk 6, 1, 0
event_5F8_command_7A26:
    event_wait_idle 
event_5F8_command_7A27:
    event_wait 24
event_5F8_command_7A29:
    event_actor_walk 4, 2, 0
event_5F8_command_7A2C:
    event_actor_walk 5, 1, 0
event_5F8_command_7A2F:
    event_actor_walk 6, 3, 0
event_5F8_command_7A32:
    event_wait_idle 
event_5F8_command_7A33:
    event_wait 24
event_5F8_command_7A35:
    event_actor_walk 4, 1, 0
event_5F8_command_7A38:
    event_actor_walk 5, 0, 0
event_5F8_command_7A3B:
    event_actor_walk 6, 2, 0
event_5F8_command_7A3E:
    event_wait_idle 
event_5F8_command_7A3F:
    event_wait 24
