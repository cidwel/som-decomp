; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7871
.include "src/rom/event_command_macros.inc"
event_1CF_command_7871:
    event_test_flag_range 15, 1, 15
event_1CF_command_7874:
    event_jump 464
event_1CF_command_7876:
    event_call 1943
event_1CF_command_7878:
    event_set_flag 88, 1
event_1CF_command_787B:
    event_increment_flag 21
event_1CF_command_787D:
    event_refresh_objects 
