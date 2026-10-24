; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4030
.include "src/rom/event_command_macros.inc"
event_4E6_command_4030:
    event_actor_walk 6, 3, 0
event_4E6_command_4033:
    event_actor_animation 0, 140
event_4E6_command_4036:
    event_wait 16
