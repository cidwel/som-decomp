; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9888
.include "src/rom/event_command_macros.inc"
event_7FE_command_9888:
    event_jump 1806
event_7FE_command_988A:
    event_end 
event_7FF_command_988B:
    event_freeze 
event_7FF_command_988C:
    event_test_flag_range 11, 0, 0
event_7FF_command_988F:
    event_jump 2046
event_7FF_command_9891:
    event_test_flag_range 11, 1, 1
event_7FF_command_9894:
    event_jump 2045
event_7FF_command_9896:
    event_test_flag_range 11, 3, 3
event_7FF_command_9899:
    event_jump 1647
event_7FF_command_989B:
    event_test_flag_range 11, 4, 4
event_7FF_command_989E:
    event_jump 37
event_7FF_command_98A0:
    event_increment_flag 255
event_7FF_command_98A2:
    event_call 1864
event_7FF_command_98A4:
    event_screen_word 6, 65535
event_7FF_command_98A8:
    event_wait 32
event_7FF_command_98AA:
    event_call 1991
event_7FF_command_98AC:
    event_set_flag 0, 0
event_7FF_command_98AF:
    event_change_map 117
