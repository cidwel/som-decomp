; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $28F4
.include "src/rom/event_command_macros.inc"
event_106_command_28F4:
    event_actor_animation_loop 0, 157
event_106_command_28F7:
    event_actor_walk 5, 2, 32
event_106_command_28FA:
    event_actor_walk 6, 2, 0
event_106_command_28FD:
    event_wait 8
