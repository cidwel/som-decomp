; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7489
.include "src/rom/event_command_macros.inc"
event_592_command_7489:
    event_actor_walk 3, 2, 0
event_592_command_748C:
    event_wait_idle 
