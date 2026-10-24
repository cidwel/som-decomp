; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8407
.include "src/rom/event_command_macros.inc"
event_5F8_command_8407:
    event_wait 32
event_5F8_command_8409:
    event_actor_walk 2, 0, 0
event_5F8_command_840C:
    event_wait 32
event_5F8_command_840E:
    event_actor_animation_loop 3, 167
event_5F8_command_8411:
    event_wait_idle 
event_5F8_command_8412:
    event_wait 0
