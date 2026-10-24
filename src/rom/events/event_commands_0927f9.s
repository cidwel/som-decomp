; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $27F9
.include "src/rom/event_command_macros.inc"
event_103_command_27F9:
    event_increment_flag 193
event_103_command_27FB:
    event_jump 1535
event_103_command_27FD:
    event_end 
event_104_command_27FE:
    event_test_flag_range 16, 1, 1
event_104_command_2801:
    event_jump 294
event_104_command_2803:
    event_test_flag_range 16, 2, 15
event_104_command_2806:
    event_jump 0
event_104_command_2808:
    event_wait 16
event_104_command_280A:
    event_actor_walk 0, 2, 0
event_104_command_280D:
    event_wait_idle 
