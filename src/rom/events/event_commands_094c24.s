; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4C24
.include "src/rom/event_command_macros.inc"
event_15E_command_4C24:
    event_jump 1535
event_15E_command_4C26:
    event_end 
event_15F_command_4C27:
    event_test_flag_range 26, 8, 15
event_15F_command_4C2A:
    event_jump 1812
event_15F_command_4C2C:
    event_call 2007
event_15F_command_4C2E:
    event_test_flag_range 26, 1, 1
event_15F_command_4C31:
    event_jump 360
event_15F_command_4C33:
    event_end 
event_160_command_4C34:
    event_jump 334
event_160_command_4C36:
    event_end 
event_161_command_4C37:
    event_jump 334
event_161_command_4C39:
    event_end 
event_162_command_4C3A:
    event_jump 334
event_162_command_4C3C:
    event_end 
event_163_command_4C3D:
    event_jump 334
event_163_command_4C3F:
    event_end 
event_164_command_4C40:
    event_jump 334
event_164_command_4C42:
    event_end 
event_165_command_4C43:
    event_jump 334
event_165_command_4C45:
    event_end 
event_166_command_4C46:
    event_jump 334
event_166_command_4C48:
    event_end 
event_167_command_4C49:
    event_freeze 
event_167_command_4C4A:
    event_gather 
event_167_command_4C4B:
    event_actor_walk 128, 0, 16
event_167_command_4C4E:
    event_actor_walk 1, 3, 16
event_167_command_4C51:
    event_actor_walk 2, 0, 0
event_167_command_4C54:
    event_actor_walk 3, 2, 16
event_167_command_4C57:
    event_wait_idle 
event_167_command_4C58:
    event_actor_walk 128, 1, 0
event_167_command_4C5B:
    event_actor_walk 1, 0, 0
event_167_command_4C5E:
    event_actor_walk 3, 0, 0
event_167_command_4C61:
    event_wait_idle 
