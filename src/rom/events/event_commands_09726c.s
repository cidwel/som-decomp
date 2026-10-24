; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $726C
.include "src/rom/event_command_macros.inc"
event_1C7_command_726C:
    event_jump 1535
event_1C7_command_726E:
    event_end 
event_1C8_command_726F:
    event_test_flag_range 21, 4, 4
event_1C8_command_7272:
    event_jump 455
event_1C8_command_7274:
    event_end 
event_1C9_command_7275:
    event_test_flag_range 20, 6, 15
event_1C9_command_7278:
    event_jump 528
event_1C9_command_727A:
    event_test_flag_range 21, 4, 4
event_1C9_command_727D:
    event_jump 458
event_1C9_command_727F:
    event_test_flag_range 21, 5, 15
event_1C9_command_7282:
    event_jump 459
event_1C9_command_7284:
    event_set_flag 5, 1
