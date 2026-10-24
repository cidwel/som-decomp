; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $21F2
.include "src/rom/event_command_macros.inc"
event_4B4_command_21F2:
    event_end 
event_4B5_command_21F3:
    event_actor_walk 128, 2, 0
event_4B5_command_21F6:
    event_wait_idle 
event_4B5_command_21F7:
    event_test_flag_range 69, 2, 2
event_4B5_command_21FA:
    event_jump 1206
event_4B5_command_21FC:
    event_jump 1423
event_4B5_command_21FE:
    event_end 
event_4B6_command_21FF:
    event_freeze 
