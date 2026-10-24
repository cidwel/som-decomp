; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9CD6
.include "src/rom/event_command_macros.inc"
event_23A_command_9CD6:
    event_actor_walk 3, 1, 0
event_23A_command_9CD9:
    event_wait_idle 
