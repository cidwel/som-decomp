; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0E3B
.include "src/rom/event_command_macros.inc"
event_400_command_0E3B:
    event_world_transition 127
event_400_command_0E3D:
    event_change_map 0
event_400_command_0E3F:
    event_decrement_flag 248
event_400_command_0E41:
    event_jump 262
event_400_command_0E43:
    event_end 
event_401_command_0E44:
    event_end 
event_402_command_0E45:
    event_end 
event_403_command_0E46:
    event_end 
event_404_command_0E47:
    event_end 
event_405_command_0E48:
    event_end 
event_406_command_0E49:
    event_end 
event_407_command_0E4A:
    event_end 
event_408_command_0E4B:
    event_test_actor_field 1, 1, 145, 128
event_408_command_0E4F:
    event_jump 1033
event_408_command_0E51:
    event_test_actor_field 1, 2, 145, 128
event_408_command_0E55:
    event_jump 1033
event_408_command_0E57:
    event_test_actor_field 1, 3, 145, 128
event_408_command_0E5B:
    event_jump 1033
event_408_command_0E5D:
    event_return 
event_408_command_0E5E:
    event_end 
