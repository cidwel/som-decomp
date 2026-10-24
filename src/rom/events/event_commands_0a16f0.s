; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $16F0
.include "src/rom/event_command_macros.inc"
event_482_command_16F0:
    event_end 
event_483_command_16F1:
    event_actor_walk 3, 3, 24
event_483_command_16F4:
    event_wait_idle 
event_483_command_16F5:
    event_actor_walk 3, 3, 24
event_483_command_16F8:
    event_actor_walk 2, 3, 24
event_483_command_16FB:
    event_wait_idle 
event_483_command_16FC:
    event_jump 1158
event_483_command_16FE:
    event_end 
event_484_command_16FF:
    event_actor_walk 2, 3, 24
event_484_command_1702:
    event_wait_idle 
event_484_command_1703:
    event_actor_walk 2, 3, 24
event_484_command_1706:
    event_actor_walk 1, 3, 24
event_484_command_1709:
    event_wait_idle 
event_484_command_170A:
    event_jump 1158
event_484_command_170C:
    event_end 
event_485_command_170D:
    event_call 1943
