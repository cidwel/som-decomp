; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $74D0
.include "src/rom/event_command_macros.inc"
event_1CA_command_74D0:
    event_wait 0
event_1CA_command_74D2:
    event_set_flag 5, 0
event_1CA_command_74D5:
    event_increment_flag 21
event_1CA_command_74D7:
    event_test_flag_range 88, 1, 1
event_1CA_command_74DA:
    event_call 466
event_1CA_command_74DC:
    event_jump 465
event_1CA_command_74DE:
    event_end 
