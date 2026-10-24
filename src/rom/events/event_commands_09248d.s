; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $248D
.include "src/rom/event_command_macros.inc"
event_0FC_command_248D:
    event_freeze 
event_0FC_command_248E:
    event_gather 
event_0FC_command_248F:
    event_actor_walk 0, 1, 8
event_0FC_command_2492:
    event_wait_idle 
event_0FC_command_2493:
    event_gather 
event_0FC_command_2494:
    event_actor_walk 0, 2, 20
event_0FC_command_2497:
    event_wait_idle 
event_0FC_command_2498:
    event_gather 
event_0FC_command_2499:
    event_actor_walk 0, 0, 48
event_0FC_command_249C:
    event_wait_idle 
event_0FC_command_249D:
    event_gather 
event_0FC_command_249E:
    event_actor_walk 0, 3, 12
event_0FC_command_24A1:
    event_wait_idle 
event_0FC_command_24A2:
    event_gather 
event_0FC_command_24A3:
    event_actor_walk 0, 0, 32
event_0FC_command_24A6:
    event_wait_idle 
event_0FC_command_24A7:
    event_gather 
event_0FC_command_24A8:
    event_actor_walk 0, 2, 12
event_0FC_command_24AB:
    event_wait_idle 
event_0FC_command_24AC:
    event_gather 
event_0FC_command_24AD:
    event_toggle_visibility_04 
event_0FC_command_24AE:
    event_gather 
event_0FC_command_24AF:
    event_screen 8
event_0FC_command_24B1:
    event_wait 32
event_0FC_command_24B3:
    event_audio_request 2, 200, 0, 204
event_0FC_command_24B8:
    event_actor_animation 9, 129
event_0FC_command_24BB:
    event_wait_idle 
event_0FC_command_24BC:
    event_wait 16
event_0FC_command_24BE:
    event_audio_request 1, 25, 10, 255
event_0FC_command_24C3:
    event_screen 0
event_0FC_command_24C5:
    event_screen 3
event_0FC_command_24C7:
    event_increment_flag 87
event_0FC_command_24C9:
    event_refresh_objects 
event_0FC_command_24CA:
    event_actor_walk 1, 3, 63
event_0FC_command_24CD:
    event_actor_walk 2, 3, 63
event_0FC_command_24D0:
    event_actor_walk 3, 3, 63
event_0FC_command_24D3:
    event_actor_walk 4, 2, 16
event_0FC_command_24D6:
    event_actor_walk 5, 2, 16
event_0FC_command_24D9:
    event_actor_walk 6, 2, 16
event_0FC_command_24DC:
    event_actor_walk 7, 2, 16
event_0FC_command_24DF:
    event_actor_walk 8, 2, 16
event_0FC_command_24E2:
    event_wait_idle 
event_0FC_command_24E3:
    event_screen 1
event_0FC_command_24E5:
    event_screen 4
event_0FC_command_24E7:
    event_wait 16
event_0FC_command_24E9:
    event_unfreeze 
event_0FC_command_24EA:
    event_audio_request 1, 26, 10, 255
event_0FC_command_24EF:
    event_set_flag 87, 0
event_0FC_command_24F2:
    event_return 
event_0FC_command_24F3:
    event_end 
event_0FD_command_24F4:
    event_object_command_37 50
