; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $66FE
.include "src/rom/event_command_macros.inc"
event_559_command_66FE:
    event_actor_walk 2, 2, 0
event_559_command_6701:
    event_wait_idle 
event_559_command_6702:
    event_wait 4
event_559_command_6704:
    event_actor_walk 2, 3, 0
event_559_command_6707:
    event_wait_idle 
event_559_command_6708:
    event_wait 4
event_559_command_670A:
    event_actor_walk 2, 2, 0
event_559_command_670D:
    event_wait_idle 
event_559_command_670E:
    event_wait 4
