; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $59BE
.include "src/rom/event_command_macros.inc"
event_50A_command_59BE:
    event_wait 2
event_50A_command_59C0:
    event_call 1281
event_50A_command_59C2:
    event_increment_flag 60
event_50A_command_59C4:
    event_end 
event_50B_command_59C5:
    event_end 
event_50C_command_59C6:
    event_end 
event_50D_command_59C7:
    event_end 
event_50E_command_59C8:
    event_end 
event_50F_command_59C9:
    event_end 
event_510_command_59CA:
    event_test_flag_range 50, 2, 2
event_510_command_59CD:
    event_jump 1297
event_510_command_59CF:
    event_end 
event_511_command_59D0:
    event_actor_walk 0, 0, 20
event_511_command_59D3:
    event_wait_idle 
event_511_command_59D4:
    event_call 1149
event_511_command_59D6:
    event_actor_walk 4, 1, 0
event_511_command_59D9:
    event_actor_walk 5, 1, 0
event_511_command_59DC:
    event_actor_walk 6, 1, 0
event_511_command_59DF:
    event_wait_idle 
