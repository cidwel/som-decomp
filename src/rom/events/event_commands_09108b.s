; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $108B
.include "src/rom/event_command_macros.inc"
event_042_command_108B:
    event_test_flag_range 198, 0, 0
event_042_command_108E:
    event_increment_flag 198
event_042_command_1090:
    event_return 
event_042_command_1091:
    event_end 
event_043_command_1092:
    event_end 
event_044_command_1093:
    event_end 
event_045_command_1094:
    event_end 
event_046_command_1095:
    event_end 
event_047_command_1096:
    event_party_command 17
event_047_command_1098:
    event_end 
event_048_command_1099:
    event_end 
event_049_command_109A:
    event_end 
event_04A_command_109B:
    event_end 
event_04B_command_109C:
    event_end 
event_04C_command_109D:
    event_end 
event_04D_command_109E:
    event_end 
event_04E_command_109F:
    event_end 
