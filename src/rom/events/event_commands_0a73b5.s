; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $73B5
.include "src/rom/event_command_macros.inc"
event_590_command_73B5:
    event_return 
event_590_command_73B6:
    event_end 
event_591_command_73B7:
    event_end 
event_592_command_73B8:
    event_freeze 
event_592_command_73B9:
    event_gather 
event_592_command_73BA:
    event_screen 8
event_592_command_73BC:
    event_screen 0
event_592_command_73BE:
    event_wait 1
event_592_command_73C0:
    event_screen 1
event_592_command_73C2:
    event_screen_word 5, 4535
event_592_command_73C6:
    event_actor_walk 128, 0, 0
event_592_command_73C9:
    event_wait_idle 
event_592_command_73CA:
    event_actor_animation_loop 128, 129
event_592_command_73CD:
    event_wait_idle 
event_592_command_73CE:
    event_wait 8
event_592_command_73D0:
    event_actor_walk 128, 2, 0
event_592_command_73D3:
    event_wait_idle 
event_592_command_73D4:
    event_call 1922
event_592_command_73D6:
    event_wait 16
event_592_command_73D8:
    event_call 1922
event_592_command_73DA:
    event_wait 16
event_592_command_73DC:
    event_call 1922
event_592_command_73DE:
    event_actor_walk 128, 1, 0
event_592_command_73E1:
    event_wait_idle 
event_592_command_73E2:
    event_actor_animation_loop 128, 129
event_592_command_73E5:
    event_wait_idle 
event_592_command_73E6:
    event_wait 8
event_592_command_73E8:
    event_actor_animation_loop 128, 128
event_592_command_73EB:
    event_wait_idle 
event_592_command_73EC:
    event_screen 7
event_592_command_73EE:
    event_set_flag 145, 1
event_592_command_73F1:
    event_refresh_objects 
event_592_command_73F2:
    event_call 1428
