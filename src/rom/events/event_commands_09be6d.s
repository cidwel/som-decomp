; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BE6D
.include "src/rom/event_command_macros.inc"
event_2CD_command_BE6D:
    event_jump 1535
event_2CD_command_BE6F:
    event_end 
event_2CE_command_BE70:
    event_test_flag_range 147, 0, 14
event_2CE_command_BE73:
    event_jump 0
event_2CE_command_BE75:
    event_set_flag 147, 14
event_2CE_command_BE78:
    event_freeze 
event_2CE_command_BE79:
    event_actor_walk 0, 0, 63
event_2CE_command_BE7C:
    event_wait_idle 
event_2CE_command_BE7D:
    event_call 1152
