; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6CA1
.include "src/rom/event_command_macros.inc"
event_581_command_6CA1:
    event_actor_walk 3, 3, 0
event_581_command_6CA4:
    event_wait_idle 
event_581_command_6CA5:
    event_actor_animation 3, 140
event_581_command_6CA8:
    event_wait_idle 
event_581_command_6CA9:
    event_actor_walk 1, 2, 0
event_581_command_6CAC:
    event_actor_animation 3, 148
event_581_command_6CAF:
    event_wait_idle 
event_581_command_6CB0:
    event_wait 16
event_581_command_6CB2:
    event_actor_walk 1, 3, 0
event_581_command_6CB5:
    event_wait_idle 
event_581_command_6CB6:
    event_wait 8
event_581_command_6CB8:
    event_actor_walk 1, 2, 0
event_581_command_6CBB:
    event_wait_idle 
event_581_command_6CBC:
    event_wait 8
event_581_command_6CBE:
    event_actor_walk 1, 0, 2
event_581_command_6CC1:
    event_wait_idle 
event_581_command_6CC2:
    event_wait 16
