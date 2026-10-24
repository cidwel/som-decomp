; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6520
.include "src/rom/event_command_macros.inc"
event_557_command_6520:
    event_end 
event_558_command_6521:
    event_freeze 
event_558_command_6522:
    event_set_actor_field 4, 144, 1
event_558_command_6526:
    event_actor_animation_loop 4, 135
event_558_command_6529:
    event_call 1151
event_558_command_652B:
    event_actor_animation_loop 1, 138
event_558_command_652E:
    event_actor_animation_loop 3, 138
event_558_command_6531:
    event_wait 8
event_558_command_6533:
    event_actor_animation_loop 1, 131
event_558_command_6536:
    event_actor_animation_loop 3, 131
event_558_command_6539:
    event_wait_idle 
event_558_command_653A:
    event_screen 8
