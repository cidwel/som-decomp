; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7604
.include "src/rom/event_command_macros.inc"
event_1CE_command_7604:
    event_actor_walk 4, 0, 0
event_1CE_command_7607:
    event_wait_idle 
event_1CE_command_7608:
    event_actor_walk 4, 2, 0
event_1CE_command_760B:
    event_wait_idle 
event_1CE_command_760C:
    event_actor_walk 4, 1, 0
event_1CE_command_760F:
    event_wait_idle 
event_1CE_command_7610:
    event_actor_walk 4, 3, 0
event_1CE_command_7613:
    event_call 1941
event_1CE_command_7615:
    event_wait 0
