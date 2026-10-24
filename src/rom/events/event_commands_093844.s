; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3844
.include "src/rom/event_command_macros.inc"
event_11B_command_3844:
    event_test_flag_range 16, 11, 15
event_11B_command_3847:
    event_jump 0
event_11B_command_3849:
    event_set_flag 16, 11
event_11B_command_384C:
    event_end 
event_11C_command_384D:
    event_actor_walk 4, 1, 36
event_11C_command_3850:
    event_wait_idle 
event_11C_command_3851:
    event_actor_walk 0, 2, 8
event_11C_command_3854:
    event_actor_walk 4, 2, 16
event_11C_command_3857:
    event_wait_idle 
event_11C_command_3858:
    event_actor_walk 0, 1, 56
event_11C_command_385B:
    event_actor_walk 4, 3, 0
event_11C_command_385E:
    event_wait_idle 
event_11C_command_385F:
    event_actor_walk 0, 0, 0
event_11C_command_3862:
    event_actor_walk 4, 3, 16
event_11C_command_3865:
    event_wait_idle 
event_11C_command_3866:
    event_actor_walk 4, 0, 36
event_11C_command_3869:
    event_wait_idle 
event_11C_command_386A:
    event_actor_walk 4, 1, 0
event_11C_command_386D:
    event_jump 283
event_11C_command_386F:
    event_end 
