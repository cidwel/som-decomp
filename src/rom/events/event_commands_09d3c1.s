; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D3C1
.include "src/rom/event_command_macros.inc"
event_36A_command_D3C1:
    event_actor_walk 4, 1, 63
event_36A_command_D3C4:
    event_actor_walk 5, 1, 63
event_36A_command_D3C7:
    event_actor_walk 6, 1, 63
event_36A_command_D3CA:
    event_wait_idle 
event_36A_command_D3CB:
    event_increment_flag 27
event_36A_command_D3CD:
    event_wait 0
