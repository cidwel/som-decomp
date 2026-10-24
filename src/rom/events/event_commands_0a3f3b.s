; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3F3B
.include "src/rom/event_command_macros.inc"
event_4E6_command_3F3B:
    event_actor_walk 4, 0, 0
event_4E6_command_3F3E:
    event_actor_walk 5, 0, 0
event_4E6_command_3F41:
    event_actor_walk 6, 2, 0
event_4E6_command_3F44:
    event_actor_walk 7, 0, 0
event_4E6_command_3F47:
    event_wait_idle 
