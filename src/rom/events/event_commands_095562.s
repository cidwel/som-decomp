; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5562
.include "src/rom/event_command_macros.inc"
event_177_command_5562:
    event_jump 1535
event_177_command_5564:
    event_end 
event_178_command_5565:
    event_end 
event_179_command_5566:
    event_end 
event_17A_command_5567:
    event_end 
event_17B_command_5568:
    event_end 
event_17C_command_5569:
    event_end 
event_17D_command_556A:
    event_end 
event_17E_command_556B:
    event_set_flag 10, 0
event_17E_command_556E:
    event_test_flag_range 19, 5, 15
event_17E_command_5571:
    event_jump 0
event_17E_command_5573:
    event_call 1151
event_17E_command_5575:
    event_actor_walk 1, 0, 60
event_17E_command_5578:
    event_actor_walk 2, 0, 60
event_17E_command_557B:
    event_actor_walk 3, 0, 60
event_17E_command_557E:
    event_wait_idle 
event_17E_command_557F:
    event_screen 8
event_17E_command_5581:
    event_actor_walk 4, 1, 0
event_17E_command_5584:
    event_wait_idle 
event_17E_command_5585:
    event_jump 384
event_17E_command_5587:
    event_end 
