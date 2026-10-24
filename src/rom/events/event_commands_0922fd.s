; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $22FD
.include "src/rom/event_command_macros.inc"
event_0F5_command_22FD:
    event_call 252
event_0F5_command_22FF:
    event_world_transition 34
event_0F5_command_2301:
    event_call 247
event_0F5_command_2303:
    event_jump 1555
event_0F5_command_2305:
    event_end 
event_0F6_command_2306:
    event_end 
event_0F7_command_2307:
    event_actor_walk 0, 3, 0
event_0F7_command_230A:
    event_wait_idle 
event_0F7_command_230B:
    event_actor_animation 1, 162
event_0F7_command_230E:
    event_actor_animation 2, 162
event_0F7_command_2311:
    event_actor_animation 3, 162
event_0F7_command_2314:
    event_wait 2
event_0F7_command_2316:
    event_actor_animation 2, 162
event_0F7_command_2319:
    event_actor_animation 3, 162
event_0F7_command_231C:
    event_toggle_visibility_05 
event_0F7_command_231D:
    event_wait 2
event_0F7_command_231F:
    event_actor_animation 3, 162
event_0F7_command_2322:
    event_wait_idle 
event_0F7_command_2323:
    event_return 
event_0F7_command_2324:
    event_end 
