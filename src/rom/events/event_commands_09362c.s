; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $362C
.include "src/rom/event_command_macros.inc"
event_112_command_362C:
    event_actor_walk 5, 3, 16
event_112_command_362F:
    event_wait_idle 
event_112_command_3630:
    event_actor_walk 5, 1, 0
event_112_command_3633:
    event_wait_idle 
event_112_command_3634:
    event_actor_walk 0, 1, 0
event_112_command_3637:
    event_actor_animation_loop 5, 129
event_112_command_363A:
    event_wait_idle 
event_112_command_363B:
    event_wait 32
event_112_command_363D:
    event_set_flag 16, 9
event_112_command_3640:
    event_refresh_objects 
event_112_command_3641:
    event_end 
event_113_command_3642:
    event_test_flag_range 16, 10, 15
event_113_command_3645:
    event_jump 0
event_113_command_3647:
    event_jump 1254
event_113_command_3649:
    event_end 
