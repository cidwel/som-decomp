; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $256C
.include "src/rom/event_command_macros.inc"
event_0FF_command_256C:
    event_end 
event_100_command_256D:
    event_test_flag_range 0, 1, 15
event_100_command_2570:
    event_jump 511
event_100_command_2572:
    event_jump 1024
event_100_command_2574:
    event_end 
event_101_command_2575:
    event_wait 16
event_101_command_2577:
    event_actor_walk 0, 3, 0
event_101_command_257A:
    event_wait_idle 
event_101_command_257B:
    event_actor_animation 0, 162
event_101_command_257E:
    event_wait 2
event_101_command_2580:
    event_toggle_visibility_05 
event_101_command_2581:
    event_audio_request 2, 32, 0, 136
event_101_command_2586:
    event_actor_walk 5, 2, 0
event_101_command_2589:
    event_wait_idle 
event_101_command_258A:
    event_call 95
