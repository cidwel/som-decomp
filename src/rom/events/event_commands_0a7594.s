; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7594
.include "src/rom/event_command_macros.inc"
event_593_command_7594:
    event_jump 1535
event_593_command_7596:
    event_end 
event_594_command_7597:
    event_test_flag_range 252, 0, 7
event_594_command_759A:
    event_increment_flag 252
event_594_command_759C:
    event_return 
event_594_command_759D:
    event_end 
event_595_command_759E:
    event_end 
event_596_command_759F:
    event_increment_flag 64
event_596_command_75A1:
    event_call 1948
event_596_command_75A3:
    event_redraw_pieces 
event_596_command_75A4:
    event_end 
event_597_command_75A5:
    event_change_map 795
event_597_command_75A7:
    event_end 
event_598_command_75A8:
    event_test_flag_range 64, 4, 15
event_598_command_75AB:
    event_jump 1431
event_598_command_75AD:
    event_change_map 794
event_598_command_75AF:
    event_jump 1796
event_598_command_75B1:
    event_end 
event_599_command_75B2:
    event_call 7
event_599_command_75B4:
    event_test_flag_range 64, 0, 0
event_599_command_75B7:
    event_jump 1430
event_599_command_75B9:
    event_end 
event_59A_command_75BA:
    event_call 7
event_59A_command_75BC:
    event_test_flag_range 64, 1, 1
event_59A_command_75BF:
    event_jump 1430
event_59A_command_75C1:
    event_end 
event_59B_command_75C2:
    event_call 1284
event_59B_command_75C4:
    event_set_flag 64, 3
event_59B_command_75C7:
    event_call 2000
event_59B_command_75C9:
    event_change_map 794
event_59B_command_75CB:
    event_actor_walk 0, 0, 8
event_59B_command_75CE:
    event_wait_idle 
event_59B_command_75CF:
    event_call 1152
event_59B_command_75D1:
    event_actor_walk 4, 1, 0
event_59B_command_75D4:
    event_actor_walk 5, 1, 0
event_59B_command_75D7:
    event_actor_walk 6, 1, 0
event_59B_command_75DA:
    event_wait_idle 
event_59B_command_75DB:
    event_actor_walk 5, 1, 8
event_59B_command_75DE:
    event_wait_idle 
