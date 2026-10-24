; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DC13
.include "src/rom/event_command_macros.inc"
event_38D_command_DC13:
    event_actor_walk 5, 1, 63
event_38D_command_DC16:
    event_actor_walk 6, 1, 63
event_38D_command_DC19:
    event_actor_walk 7, 1, 63
event_38D_command_DC1C:
    event_wait_idle 
event_38D_command_DC1D:
    event_call 83
event_38D_command_DC1F:
    event_actor_walk 5, 1, 63
event_38D_command_DC22:
    event_actor_walk 6, 1, 63
event_38D_command_DC25:
    event_actor_walk 7, 1, 63
event_38D_command_DC28:
    event_wait_idle 
event_38D_command_DC29:
    event_increment_flag 39
event_38D_command_DC2B:
    event_refresh_objects 
event_38D_command_DC2C:
    event_jump 1828
event_38D_command_DC2E:
    event_end 
