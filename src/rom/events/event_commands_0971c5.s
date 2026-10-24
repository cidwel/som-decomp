; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $71C5
.include "src/rom/event_command_macros.inc"
event_1C6_command_71C5:
    event_jump 442
event_1C6_command_71C7:
    event_end 
event_1C7_command_71C8:
    event_actor_walk 0, 0, 16
event_1C7_command_71CB:
    event_actor_walk 4, 3, 0
event_1C7_command_71CE:
    event_actor_walk 5, 2, 0
event_1C7_command_71D1:
    event_freeze 
event_1C7_command_71D2:
    event_gather 
event_1C7_command_71D3:
    event_screen 8
