; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $61EB
.include "src/rom/event_command_macros.inc"
event_19C_command_61EB:
    event_jump 1535
event_19C_command_61ED:
    event_end 
event_19D_command_61EE:
    event_end 
event_19E_command_61EF:
    event_test_flag_range 13, 1, 1
event_19E_command_61F2:
    event_jump 415
event_19E_command_61F4:
    event_end 
event_19F_command_61F5:
    event_test_flag_range 19, 4, 15
event_19F_command_61F8:
    event_jump 0
event_19F_command_61FA:
    event_freeze 
event_19F_command_61FB:
    event_actor_walk 0, 0, 16
event_19F_command_61FE:
    event_wait_idle 
event_19F_command_61FF:
    event_actor_walk 4, 1, 16
event_19F_command_6202:
    event_wait_idle 
