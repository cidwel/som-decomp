; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $426C
.include "src/rom/event_command_macros.inc"
event_4E8_command_426C:
    event_actor_animation_loop 5, 1
event_4E8_command_426F:
    event_actor_animation_loop 6, 1
event_4E8_command_4272:
    event_screen 0
event_4E8_command_4274:
    event_wait 2
event_4E8_command_4276:
    event_screen 1
event_4E8_command_4278:
    event_call 1934
