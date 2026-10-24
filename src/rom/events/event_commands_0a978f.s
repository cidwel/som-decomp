; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $978F
.include "src/rom/event_command_macros.inc"
event_7F8_command_978F:
    event_gather 
event_7F8_command_9790:
    event_end 
event_7F9_command_9791:
    event_screen 7
event_7F9_command_9793:
    event_wait 64
event_7F9_command_9795:
    event_call 1051
event_7F9_command_9797:
    event_end 
event_7FA_command_9798:
    event_test_flag_range 14, 0, 0
event_7FA_command_979B:
    event_jump 2035
