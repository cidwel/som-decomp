; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B0D3
.include "src/rom/event_command_macros.inc"
event_29B_command_B0D3:
    event_end 
event_29C_command_B0D4:
    event_test_flag_range 40, 8, 15
event_29C_command_B0D7:
    event_jump 0
event_29C_command_B0D9:
    event_freeze 
event_29C_command_B0DA:
    event_increment_flag 1
event_29C_command_B0DC:
    event_actor_walk 0, 0, 28
event_29C_command_B0DF:
    event_wait_idle 
event_29C_command_B0E0:
    event_call 1149
