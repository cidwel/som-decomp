; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6229
.include "src/rom/event_command_macros.inc"
event_19F_command_6229:
    event_actor_walk 2, 1, 8
event_19F_command_622C:
    event_wait_idle 
event_19F_command_622D:
    event_change_map 232
event_19F_command_622F:
    event_actor_walk 2, 1, 8
event_19F_command_6232:
    event_wait_idle 
event_19F_command_6233:
    event_actor_walk 2, 0, 0
event_19F_command_6236:
    event_wait_idle 
