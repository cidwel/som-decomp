; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3C10
.include "src/rom/event_command_macros.inc"
event_4E4_command_3C10:
    event_increment_flag 36
event_4E4_command_3C12:
    event_end 
event_4E5_command_3C13:
    event_test_flag_range 63, 6, 15
event_4E5_command_3C16:
    event_jump 1120
event_4E5_command_3C18:
    event_test_actor_field 2, 4, 145, 127
event_4E5_command_3C1C:
    event_jump 990
event_4E5_command_3C1E:
    event_test_actor_field 2, 5, 145, 127
event_4E5_command_3C22:
    event_jump 990
event_4E5_command_3C24:
    event_test_actor_field 2, 6, 145, 127
event_4E5_command_3C28:
    event_jump 990
event_4E5_command_3C2A:
    event_set_flag 63, 6
event_4E5_command_3C2D:
    event_change_map 56
event_4E5_command_3C2F:
    event_freeze 
event_4E5_command_3C30:
    event_actor_walk 0, 1, 32
event_4E5_command_3C33:
    event_wait_idle 
event_4E5_command_3C34:
    event_gather 
event_4E5_command_3C35:
    event_actor_walk 0, 2, 32
event_4E5_command_3C38:
    event_wait_idle 
event_4E5_command_3C39:
    event_call 1152
