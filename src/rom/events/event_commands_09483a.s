; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $483A
.include "src/rom/event_command_macros.inc"
event_14E_command_483A:
    event_jump 1535
event_14E_command_483C:
    event_end 
event_14F_command_483D:
    event_end 
event_150_command_483E:
    event_test_flag_range 18, 0, 8
event_150_command_4841:
    event_jump 334
