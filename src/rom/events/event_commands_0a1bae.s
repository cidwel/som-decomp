; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1BAE
.include "src/rom/event_command_macros.inc"
event_4AA_command_1BAE:
    event_actor_walk 3, 2, 16
event_4AA_command_1BB1:
    event_wait_idle 
event_4AA_command_1BB2:
    event_actor_walk 3, 0, 8
event_4AA_command_1BB5:
    event_wait_idle 
event_4AA_command_1BB6:
    event_wait 16
event_4AA_command_1BB8:
    event_actor_walk 3, 1, 0
event_4AA_command_1BBB:
    event_wait_idle 
