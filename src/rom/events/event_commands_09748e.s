; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $748E
.include "src/rom/event_command_macros.inc"
event_1CA_command_748E:
    event_actor_walk 5, 3, 0
event_1CA_command_7491:
    event_wait_idle 
event_1CA_command_7492:
    event_actor_walk 5, 0, 0
event_1CA_command_7495:
    event_wait 0
