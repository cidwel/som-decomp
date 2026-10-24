; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8552
.include "src/rom/event_command_macros.inc"
event_5F8_command_8552:
    event_actor_animation_loop 1, 171
event_5F8_command_8555:
    event_actor_animation_loop 2, 171
event_5F8_command_8558:
    event_actor_animation_loop 3, 171
event_5F8_command_855B:
    event_wait_idle 
event_5F8_command_855C:
    event_wait 0
