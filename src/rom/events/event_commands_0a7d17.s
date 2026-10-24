; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7D17
.include "src/rom/event_command_macros.inc"
event_5F8_command_7D17:
    event_decrement_flag 248
event_5F8_command_7D19:
    event_call 1045
event_5F8_command_7D1B:
    event_wait 11
event_5F8_command_7D1D:
    event_actor_animation_loop 1, 128
event_5F8_command_7D20:
    event_wait_idle 
event_5F8_command_7D21:
    event_wait 32
event_5F8_command_7D23:
    event_actor_walk 1, 1, 0
event_5F8_command_7D26:
    event_wait_idle 
event_5F8_command_7D27:
    event_call 1054
event_5F8_command_7D29:
    event_wait 11
event_5F8_command_7D2B:
    event_call 82
event_5F8_command_7D2D:
    event_screen 8
