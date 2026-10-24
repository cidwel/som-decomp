; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D504
.include "src/rom/event_command_macros.inc"
event_36D_command_D504:
    event_decrement_flag 255
event_36D_command_D506:
    event_end 
event_36E_command_D507:
    event_test_flag_range 27, 4, 15
event_36E_command_D50A:
    event_change_map 418
event_36E_command_D50C:
    event_end 
event_36F_command_D50D:
    event_freeze 
event_36F_command_D50E:
    event_actor_walk 0, 0, 8
event_36F_command_D511:
    event_wait_idle 
event_36F_command_D512:
    event_call 1152
