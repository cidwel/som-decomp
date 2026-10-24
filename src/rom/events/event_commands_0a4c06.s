; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4C06
.include "src/rom/event_command_macros.inc"
event_4EA_command_4C06:
    event_actor_walk 6, 2, 0
event_4EA_command_4C09:
    event_actor_walk 7, 2, 0
event_4EA_command_4C0C:
    event_actor_walk 8, 2, 0
event_4EA_command_4C0F:
    event_actor_walk 9, 2, 0
event_4EA_command_4C12:
    event_actor_walk 10, 2, 0
event_4EA_command_4C15:
    event_actor_walk 11, 2, 0
event_4EA_command_4C18:
    event_actor_walk 12, 2, 0
event_4EA_command_4C1B:
    event_actor_walk 0, 3, 0
event_4EA_command_4C1E:
    event_wait_idle 
