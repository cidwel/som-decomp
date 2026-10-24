; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CA90
.include "src/rom/event_command_macros.inc"
event_2F9_command_CA90:
    event_jump 1809
event_2F9_command_CA92:
    event_end 
event_2FA_command_CA93:
    event_test_flag_range 111, 0, 2
event_2FA_command_CA96:
    event_jump 1809
event_2FA_command_CA98:
    event_jump 1806
event_2FA_command_CA9A:
    event_end 
event_2FB_command_CA9B:
    event_change_map 630
event_2FB_command_CA9D:
    event_test_flag_range 111, 2, 2
event_2FB_command_CAA0:
    event_jump 764
event_2FB_command_CAA2:
    event_end 
event_2FC_command_CAA3:
    event_call 1853
