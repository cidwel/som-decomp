; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E11D
.include "src/rom/event_command_macros.inc"
event_3A7_command_E11D:
    event_set_flag 10, 1
event_3A7_command_E120:
    event_end 
event_3A8_command_E121:
    event_set_flag 10, 0
event_3A8_command_E124:
    event_call 1998
event_3A8_command_E126:
    event_call 1933
event_3A8_command_E128:
    event_end 
event_3A9_command_E129:
    event_call 1987
event_3A9_command_E12B:
    event_test_flag_range 50, 0, 0
event_3A9_command_E12E:
    event_jump 938
event_3A9_command_E130:
    event_end 
event_3AA_command_E131:
    event_call 1151
event_3AA_command_E133:
    event_actor_walk 4, 1, 0
event_3AA_command_E136:
    event_actor_walk 5, 1, 0
event_3AA_command_E139:
    event_actor_walk 6, 1, 0
event_3AA_command_E13C:
    event_wait_idle 
