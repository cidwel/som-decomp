; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $390E
.include "src/rom/event_command_macros.inc"
event_120_command_390E:
    event_increment_flag 1
event_120_command_3910:
    event_call 269
event_120_command_3912:
    event_actor_walk 0, 3, 0
event_120_command_3915:
    event_call 269
event_120_command_3917:
    event_call 269
event_120_command_3919:
    event_call 269
event_120_command_391B:
    event_call 269
event_120_command_391D:
    event_call 1939
event_120_command_391F:
    event_set_flag 17, 2
event_120_command_3922:
    event_decrement_flag 1
event_120_command_3924:
    event_refresh_objects 
event_120_command_3925:
    event_end 
event_121_command_3926:
    event_test_flag_range 17, 1, 15
event_121_command_3929:
    event_jump 288
