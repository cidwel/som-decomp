; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $89CF
.include "src/rom/event_command_macros.inc"
event_1F5_command_89CF:
    event_jump 1535
event_1F5_command_89D1:
    event_end 
event_1F6_command_89D2:
    event_call 2010
event_1F6_command_89D4:
    event_freeze 
event_1F6_command_89D5:
    event_actor_walk 2, 1, 32
event_1F6_command_89D8:
    event_actor_walk 3, 1, 12
event_1F6_command_89DB:
    event_wait_idle 
