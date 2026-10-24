; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $56F9
.include "src/rom/event_command_macros.inc"
event_180_command_56F9:
    event_actor_walk 4, 3, 16
event_180_command_56FC:
    event_wait_idle 
event_180_command_56FD:
    event_actor_walk 4, 1, 0
event_180_command_5700:
    event_wait_idle 
event_180_command_5701:
    event_actor_walk 0, 1, 0
event_180_command_5704:
    event_actor_animation_loop 4, 129
event_180_command_5707:
    event_wait_idle 
event_180_command_5708:
    event_wait 32
event_180_command_570A:
    event_set_flag 19, 5
event_180_command_570D:
    event_refresh_objects 
event_180_command_570E:
    event_end 
