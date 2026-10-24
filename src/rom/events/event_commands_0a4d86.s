; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4D86
.include "src/rom/event_command_macros.inc"
event_4F0_command_4D86:
    event_jump 1535
event_4F0_command_4D88:
    event_end 
event_4F1_command_4D89:
    event_end 
event_4F2_command_4D8A:
    event_end 
event_4F3_command_4D8B:
    event_end 
event_4F4_command_4D8C:
    event_end 
event_4F5_command_4D8D:
    event_end 
event_4F6_command_4D8E:
    event_end 
event_4F7_command_4D8F:
    event_end 
event_4F8_command_4D90:
    event_end 
event_4F9_command_4D91:
    event_end 
event_4FA_command_4D92:
    event_end 
event_4FB_command_4D93:
    event_end 
event_4FC_command_4D94:
    event_end 
event_4FD_command_4D95:
    event_freeze 
event_4FD_command_4D96:
    event_gather 
event_4FD_command_4D97:
    event_call 1864
event_4FD_command_4D99:
    event_screen_word 6, 16383
event_4FD_command_4D9D:
    event_wait 48
event_4FD_command_4D9F:
    event_set_flag 0, 0
event_4FD_command_4DA2:
    event_actor_animation_loop 1, 171
event_4FD_command_4DA5:
    event_actor_animation_loop 2, 171
event_4FD_command_4DA8:
    event_wait_idle 
event_4FD_command_4DA9:
    event_call 1054
event_4FD_command_4DAB:
    event_delete_actor 1
event_4FD_command_4DAD:
    event_delete_actor 2
event_4FD_command_4DAF:
    event_clone_actor 1
event_4FD_command_4DB1:
    event_world_transition 126
event_4FD_command_4DB3:
    event_call 1850
event_4FD_command_4DB5:
    event_wait 48
event_4FD_command_4DB7:
    event_change_map 1023
event_4FD_command_4DB9:
    event_actor_walk 1, 1, 8
event_4FD_command_4DBC:
    event_actor_walk 2, 1, 16
event_4FD_command_4DBF:
    event_wait_idle 
event_4FD_command_4DC0:
    event_actor_walk 1, 3, 4
event_4FD_command_4DC3:
    event_actor_walk 2, 2, 4
event_4FD_command_4DC6:
    event_wait_idle 
