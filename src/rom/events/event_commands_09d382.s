; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D382
.include "src/rom/event_command_macros.inc"
event_367_command_D382:
    event_end 
event_368_command_D383:
    event_test_flag_range 215, 0, 0
event_368_command_D386:
    event_jump 867
event_368_command_D388:
    event_change_map 450
event_368_command_D38A:
    event_jump 1824
event_368_command_D38C:
    event_end 
event_369_command_D38D:
    event_test_flag_range 27, 1, 1
event_369_command_D390:
    event_jump 879
event_369_command_D392:
    event_end 
event_36A_command_D393:
    event_freeze 
event_36A_command_D394:
    event_call 1287
event_36A_command_D396:
    event_call 1987
event_36A_command_D398:
    event_increment_flag 27
event_36A_command_D39A:
    event_change_map 418
