; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4437
.include "src/rom/event_command_macros.inc"
event_4E8_command_4437:
    event_call 301
event_4E8_command_4439:
    event_actor_animation 4, 139
event_4E8_command_443C:
    event_wait_idle 
event_4E8_command_443D:
    event_actor_animation_loop 4, 157
event_4E8_command_4440:
    event_wait_idle 
