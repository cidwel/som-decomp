; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8751
.include "src/rom/event_command_macros.inc"
event_1EC_command_8751:
    event_test_flag_range 20, 7, 15
event_1EC_command_8754:
    event_jump 0
event_1EC_command_8756:
    event_test_flag_range 13, 1, 1
event_1EC_command_8759:
    event_jump 509
event_1EC_command_875B:
    event_end 
event_1ED_command_875C:
    event_freeze 
event_1ED_command_875D:
    event_actor_walk 0, 0, 0
event_1ED_command_8760:
    event_wait_idle 
event_1ED_command_8761:
    event_gather 
event_1ED_command_8762:
    event_screen 8
event_1ED_command_8764:
    event_actor_walk 4, 0, 8
event_1ED_command_8767:
    event_wait_idle 
event_1ED_command_8768:
    event_actor_walk 4, 1, 0
event_1ED_command_876B:
    event_wait_idle 
event_1ED_command_876C:
    event_call 96
event_1ED_command_876E:
    event_call 1152
