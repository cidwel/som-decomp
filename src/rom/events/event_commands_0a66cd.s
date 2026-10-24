; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $66CD
.include "src/rom/event_command_macros.inc"
event_558_command_66CD:
    event_decrement_flag 248
event_558_command_66CF:
    event_increment_flag 45
event_558_command_66D1:
    event_change_map 792
event_558_command_66D3:
    event_jump 1796
event_558_command_66D5:
    event_end 
event_559_command_66D6:
    event_call 1286
event_559_command_66D8:
    event_call 2008
event_559_command_66DA:
    event_increment_flag 45
event_559_command_66DC:
    event_change_map 793
event_559_command_66DE:
    event_call 1149
event_559_command_66E0:
    event_actor_walk 1, 0, 8
event_559_command_66E3:
    event_actor_walk 2, 0, 8
event_559_command_66E6:
    event_actor_walk 3, 0, 8
event_559_command_66E9:
    event_wait_idle 
