; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D419
.include "src/rom/event_command_macros.inc"
event_36A_command_D419:
    event_set_flag 17, 14
event_36A_command_D41C:
    event_set_flag 30, 1
event_36A_command_D41F:
    event_set_flag 80, 1
event_36A_command_D422:
    event_end 
event_36B_command_D423:
    event_change_map 415
event_36B_command_D425:
    event_test_flag_range 27, 0, 3
event_36B_command_D428:
    event_jump 877
event_36B_command_D42A:
    event_end 
event_36C_command_D42B:
    event_change_map 416
event_36C_command_D42D:
    event_test_flag_range 27, 0, 3
event_36C_command_D430:
    event_jump 877
event_36C_command_D432:
    event_end 
event_36D_command_D433:
    event_call 1152
event_36D_command_D435:
    event_increment_flag 255
event_36D_command_D437:
    event_call 1988
