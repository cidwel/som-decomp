; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2874
.include "src/rom/event_command_macros.inc"
event_4D8_command_2874:
    event_decrement_flag 248
event_4D8_command_2876:
    event_return 
event_4D8_command_2877:
    event_end 
event_4D9_command_2878:
    event_end 
event_4DA_command_2879:
    event_end 
event_4DB_command_287A:
    event_end 
event_4DC_command_287B:
    event_end 
event_4DD_command_287C:
    event_end 
event_4DE_command_287D:
    event_end 
event_4DF_command_287E:
    event_end 
event_4E0_command_287F:
    event_test_flag_range 65, 4, 15
event_4E0_command_2882:
    event_jump 45
event_4E0_command_2884:
    event_set_flag 65, 4
event_4E0_command_2887:
    event_call 1152
event_4E0_command_2889:
    event_call 96
