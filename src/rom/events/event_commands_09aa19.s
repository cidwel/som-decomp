; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AA19
.include "src/rom/event_command_macros.inc"
event_28B_command_AA19:
    event_actor_walk 5, 2, 16
event_28B_command_AA1C:
    event_actor_walk 6, 3, 16
event_28B_command_AA1F:
    event_wait_idle 
event_28B_command_AA20:
    event_actor_walk 5, 1, 0
event_28B_command_AA23:
    event_actor_walk 6, 1, 0
event_28B_command_AA26:
    event_wait_idle 
