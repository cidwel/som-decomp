; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3220
.include "src/rom/event_command_macros.inc"
event_10C_command_3220:
    event_set_flag 11, 1
event_10C_command_3223:
    event_decrement_flag 255
event_10C_command_3225:
    event_unfreeze 
event_10C_command_3226:
    event_end 
event_10D_command_3227:
    event_actor_walk 4, 3, 63
event_10D_command_322A:
    event_actor_walk 5, 3, 63
event_10D_command_322D:
    event_actor_walk 6, 3, 63
event_10D_command_3230:
    event_actor_walk 7, 3, 63
event_10D_command_3233:
    event_actor_walk 8, 3, 63
event_10D_command_3236:
    event_wait_idle 
event_10D_command_3237:
    event_return 
event_10D_command_3238:
    event_end 
