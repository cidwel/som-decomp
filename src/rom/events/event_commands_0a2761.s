; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2761
.include "src/rom/event_command_macros.inc"
event_4CA_command_2761:
    event_actor_walk 4, 0, 0
event_4CA_command_2764:
    event_actor_walk 5, 0, 0
event_4CA_command_2767:
    event_actor_walk 6, 0, 0
event_4CA_command_276A:
    event_wait_idle 
event_4CA_command_276B:
    event_actor_animation_loop 4, 129
event_4CA_command_276E:
    event_actor_animation_loop 5, 129
event_4CA_command_2771:
    event_actor_animation_loop 6, 129
event_4CA_command_2774:
    event_wait_idle 
event_4CA_command_2775:
    event_wait 32
event_4CA_command_2777:
    event_set_flag 71, 3
event_4CA_command_277A:
    event_refresh_objects 
event_4CA_command_277B:
    event_change_map 1022
event_4CA_command_277D:
    event_jump 1576
event_4CA_command_277F:
    event_end 
event_4CB_command_2780:
    event_change_map 967
event_4CB_command_2782:
    event_jump 1224
event_4CB_command_2784:
    event_end 
event_4CC_command_2785:
    event_end 
event_4CD_command_2786:
    event_end 
event_4CE_command_2787:
    event_end 
event_4CF_command_2788:
    event_end 
