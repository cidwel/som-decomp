; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $76E7
.include "src/rom/event_command_macros.inc"
event_59B_command_76E7:
    event_screen_word 6, 16383
event_59B_command_76EB:
    event_actor_walk 5, 2, 16
event_59B_command_76EE:
    event_wait_idle 
event_59B_command_76EF:
    event_actor_walk 5, 0, 0
event_59B_command_76F2:
    event_wait_idle 
event_59B_command_76F3:
    event_actor_animation_loop 5, 129
event_59B_command_76F6:
    event_wait_idle 
event_59B_command_76F7:
    event_wait 32
