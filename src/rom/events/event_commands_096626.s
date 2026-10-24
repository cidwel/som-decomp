; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6626
.include "src/rom/event_command_macros.inc"
event_1B2_command_6626:
    event_test_flag_range 15, 1, 15
event_1B2_command_6629:
    event_jump 823
event_1B2_command_662B:
    event_call 1943
event_1B2_command_662D:
    event_freeze 
event_1B2_command_662E:
    event_actor_walk 0, 0, 0
event_1B2_command_6631:
    event_gather 
event_1B2_command_6632:
    event_screen 8
event_1B2_command_6634:
    event_actor_animation 0, 140
event_1B2_command_6637:
    event_wait_idle 
event_1B2_command_6638:
    event_actor_animation_loop 1, 176
event_1B2_command_663B:
    event_actor_animation_loop 2, 176
event_1B2_command_663E:
    event_wait_idle 
