; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D554
.include "src/rom/event_command_macros.inc"
event_36F_command_D554:
    event_actor_walk 7, 1, 24
event_36F_command_D557:
    event_actor_walk 1, 1, 4
event_36F_command_D55A:
    event_actor_walk 2, 1, 4
event_36F_command_D55D:
    event_actor_walk 3, 1, 4
event_36F_command_D560:
    event_wait_idle 
event_36F_command_D561:
    event_call 82
