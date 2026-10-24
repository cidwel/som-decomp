; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A848
.include "src/rom/event_command_macros.inc"
event_27C_command_A848:
    event_end 
event_27D_command_A849:
    event_change_map 366
event_27D_command_A84B:
    event_call 1997
event_27D_command_A84D:
    event_test_flag_range 36, 5, 5
event_27D_command_A850:
    event_increment_flag 36
event_27D_command_A852:
    event_end 
event_27E_command_A853:
    event_call 848
event_27E_command_A855:
    event_test_flag_range 36, 4, 15
event_27E_command_A858:
    event_jump 0
event_27E_command_A85A:
    event_test_flag_range 152, 1, 1
event_27E_command_A85D:
    event_jump 636
event_27E_command_A85F:
    event_call 1945
event_27E_command_A861:
    event_end 
event_27F_command_A862:
    event_test_flag_range 36, 8, 15
event_27F_command_A865:
    event_jump 1542
