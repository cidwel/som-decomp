; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6C6F
.include "src/rom/event_command_macros.inc"
event_581_command_6C6F:
    event_actor_walk 2, 2, 0
event_581_command_6C72:
    event_wait_idle 
event_581_command_6C73:
    event_actor_animation 2, 140
event_581_command_6C76:
    event_wait_idle 
event_581_command_6C77:
    event_actor_walk 1, 3, 0
event_581_command_6C7A:
    event_actor_animation 2, 148
event_581_command_6C7D:
    event_wait_idle 
event_581_command_6C7E:
    event_wait 16
