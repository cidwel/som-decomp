; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $565F
.include "src/rom/event_command_macros.inc"
event_4FD_command_565F:
    event_call 92
event_4FD_command_5661:
    event_wait 16
event_4FD_command_5663:
    event_call 89
event_4FD_command_5665:
    event_wait 32
event_4FD_command_5667:
    event_delete_actor 1
event_4FD_command_5669:
    event_increment_flag 104
event_4FD_command_566B:
    event_refresh_objects 
event_4FD_command_566C:
    event_actor_walk 1, 3, 0
event_4FD_command_566F:
    event_wait_idle 
event_4FD_command_5670:
    event_actor_animation_loop 1, 137
event_4FD_command_5673:
    event_wait_idle 
event_4FD_command_5674:
    event_wait 8
event_4FD_command_5676:
    event_change_map 66
event_4FD_command_5678:
    event_actor_walk 1, 0, 63
event_4FD_command_567B:
    event_wait_idle 
event_4FD_command_567C:
    event_actor_walk 1, 0, 63
event_4FD_command_567F:
    event_wait_idle 
event_4FD_command_5680:
    event_actor_walk 1, 0, 52
event_4FD_command_5683:
    event_wait_idle 
