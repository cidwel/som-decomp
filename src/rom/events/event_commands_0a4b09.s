; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4B09
.include "src/rom/event_command_macros.inc"
event_4EA_command_4B09:
    event_actor_walk 6, 0, 0
event_4EA_command_4B0C:
    event_actor_walk 7, 0, 0
event_4EA_command_4B0F:
    event_actor_walk 8, 0, 0
event_4EA_command_4B12:
    event_actor_walk 9, 0, 0
event_4EA_command_4B15:
    event_actor_walk 10, 0, 0
event_4EA_command_4B18:
    event_actor_walk 11, 0, 0
event_4EA_command_4B1B:
    event_actor_walk 12, 0, 0
