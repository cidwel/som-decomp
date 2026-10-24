; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A893
.include "src/rom/event_command_macros.inc"
event_27F_command_A893:
    event_jump 1535
event_27F_command_A895:
    event_end 
event_280_command_A896:
    event_test_flag_range 10, 1, 1
event_280_command_A899:
    event_jump 0
event_280_command_A89B:
    event_audio_request 1, 22, 24, 72
event_280_command_A8A0:
    event_end 
event_281_command_A8A1:
    event_test_flag_range 36, 0, 4
event_281_command_A8A4:
    event_jump 1796
event_281_command_A8A6:
    event_end 
event_282_command_A8A7:
    event_call 1051
event_282_command_A8A9:
    event_call 1281
event_282_command_A8AB:
    event_call 1997
event_282_command_A8AD:
    event_set_flag 36, 5
event_282_command_A8B0:
    event_refresh_objects 
event_282_command_A8B1:
    event_end 
event_283_command_A8B2:
    event_end 
event_284_command_A8B3:
    event_jump 1252
event_284_command_A8B5:
    event_end 
event_285_command_A8B6:
    event_test_flag_range 36, 5, 15
event_285_command_A8B9:
    event_jump 637
event_285_command_A8BB:
    event_end 
event_286_command_A8BC:
    event_test_flag_range 36, 5, 15
event_286_command_A8BF:
    event_change_map 367
event_286_command_A8C1:
    event_test_flag_range 36, 5, 15
event_286_command_A8C4:
    event_call 1997
event_286_command_A8C6:
    event_end 
event_287_command_A8C7:
    event_test_flag_range 36, 4, 15
event_287_command_A8CA:
    event_jump 1806
event_287_command_A8CC:
    event_set_flag 36, 3
event_287_command_A8CF:
    event_set_flag 10, 1
event_287_command_A8D2:
    event_call 1997
event_287_command_A8D4:
    event_end 
event_288_command_A8D5:
    event_test_flag_range 40, 0, 13
event_288_command_A8D8:
    event_jump 649
event_288_command_A8DA:
    event_call 1986
event_288_command_A8DC:
    event_change_map 404
event_288_command_A8DE:
    event_end 
event_289_command_A8DF:
    event_call 1986
event_289_command_A8E1:
    event_call 1150
event_289_command_A8E3:
    event_test_flag_range 54, 1, 15
event_289_command_A8E6:
    event_jump 0
event_289_command_A8E8:
    event_call 93
