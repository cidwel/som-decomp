; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1E8F
.include "src/rom/event_command_macros.inc"
event_4B2_command_1E8F:
    event_end 
event_4B3_command_1E90:
    event_freeze 
event_4B3_command_1E91:
    event_call 2009
event_4B3_command_1E93:
    event_actor_walk 1, 0, 16
event_4B3_command_1E96:
    event_actor_walk 3, 0, 8
event_4B3_command_1E99:
    event_wait_idle 
event_4B3_command_1E9A:
    event_actor_walk 1, 0, 32
event_4B3_command_1E9D:
    event_actor_walk 2, 0, 32
event_4B3_command_1EA0:
    event_actor_walk 3, 0, 32
event_4B3_command_1EA3:
    event_wait_idle 
event_4B3_command_1EA4:
    event_actor_walk 1, 0, 48
event_4B3_command_1EA7:
    event_actor_walk 2, 0, 63
event_4B3_command_1EAA:
    event_actor_walk 3, 0, 56
event_4B3_command_1EAD:
    event_wait_idle 
event_4B3_command_1EAE:
    event_call 1152
event_4B3_command_1EB0:
    event_actor_walk 4, 1, 8
event_4B3_command_1EB3:
    event_call 96
event_4B3_command_1EB5:
    event_set_flag 144, 2
event_4B3_command_1EB8:
    event_set_flag 145, 2
event_4B3_command_1EBB:
    event_set_flag 146, 2
event_4B3_command_1EBE:
    event_set_flag 147, 2
event_4B3_command_1EC1:
    event_set_flag 148, 2
event_4B3_command_1EC4:
    event_set_flag 149, 2
event_4B3_command_1EC7:
    event_set_flag 150, 2
event_4B3_command_1ECA:
    event_set_flag 17, 15
