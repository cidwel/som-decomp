; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0B49
.include "src/rom/event_command_macros.inc"
event_024_command_0B49:
    event_end 
event_025_command_0B4A:
    event_call 1864
event_025_command_0B4C:
    event_screen_word 6, 65535
event_025_command_0B50:
    event_wait 32
event_025_command_0B52:
    event_change_map 56
event_025_command_0B54:
    event_call 1865
event_025_command_0B56:
    event_test_flag_range 63, 6, 15
event_025_command_0B59:
    event_jump 39
