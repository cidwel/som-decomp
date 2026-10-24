; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4A15
.include "src/rom/event_command_macros.inc"
event_4EA_command_4A15:
    event_actor_walk 6, 2, 0
event_4EA_command_4A18:
    event_actor_walk 7, 2, 0
event_4EA_command_4A1B:
    event_actor_walk 8, 2, 0
event_4EA_command_4A1E:
    event_actor_walk 9, 2, 0
event_4EA_command_4A21:
    event_actor_walk 10, 2, 0
event_4EA_command_4A24:
    event_actor_walk 11, 2, 0
event_4EA_command_4A27:
    event_actor_walk 12, 2, 0
