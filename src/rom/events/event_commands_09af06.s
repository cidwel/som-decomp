; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AF06
.include "src/rom/event_command_macros.inc"
event_294_command_AF06:
    event_jump 1535
event_294_command_AF08:
    event_end 
event_295_command_AF09:
    event_test_flag_range 40, 5, 15
event_295_command_AF0C:
    event_jump 0
event_295_command_AF0E:
    event_actor_animation_loop 4, 168
event_295_command_AF11:
    event_wait_idle 
event_295_command_AF12:
    event_actor_walk 0, 0, 24
event_295_command_AF15:
    event_wait_idle 
event_295_command_AF16:
    event_screen 8
