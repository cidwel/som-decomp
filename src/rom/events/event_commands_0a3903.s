; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3903
.include "src/rom/event_command_macros.inc"
event_4E3_command_3903:
    event_test_flag_range 36, 3, 15
event_4E3_command_3906:
    event_jump 0
event_4E3_command_3908:
    event_set_flag 36, 3
event_4E3_command_390B:
    event_end 
event_4E4_command_390C:
    event_test_flag_range 36, 7, 15
event_4E4_command_390F:
    event_jump 0
event_4E4_command_3911:
    event_call 1151
