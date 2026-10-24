; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $197F
.include "src/rom/event_command_macros.inc"
event_4A1_command_197F:
    event_actor_walk 6, 0, 0
event_4A1_command_1982:
    event_wait_idle 
event_4A1_command_1983:
    event_actor_animation_loop 6, 129
