; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $54E8
.include "src/rom/event_command_macros.inc"
event_4FD_command_54E8:
    event_change_map 1009
event_4FD_command_54EA:
    event_actor_walk 1, 2, 8
event_4FD_command_54ED:
    event_wait_idle 
event_4FD_command_54EE:
    event_actor_walk 1, 2, 56
event_4FD_command_54F1:
    event_actor_walk 2, 2, 56
event_4FD_command_54F4:
    event_wait_idle 
event_4FD_command_54F5:
    event_actor_walk 1, 2, 56
event_4FD_command_54F8:
    event_actor_walk 2, 2, 56
event_4FD_command_54FB:
    event_wait_idle 
event_4FD_command_54FC:
    event_actor_walk 1, 1, 48
event_4FD_command_54FF:
    event_actor_walk 2, 1, 56
event_4FD_command_5502:
    event_wait_idle 
event_4FD_command_5503:
    event_call 85
