; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $308C
.include "src/rom/event_command_macros.inc"
event_10C_command_308C:
    event_call 1927
event_10C_command_308E:
    event_actor_walk 0, 1, 4
event_10C_command_3091:
    event_wait_idle 
event_10C_command_3092:
    event_actor_walk 0, 0, 0
event_10C_command_3095:
    event_wait_idle 
event_10C_command_3096:
    event_wait 0
