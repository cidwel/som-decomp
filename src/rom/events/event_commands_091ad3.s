; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1AD3
.include "src/rom/event_command_macros.inc"
event_0CD_command_1AD3:
    event_call 252
event_0CD_command_1AD5:
    event_world_transition 35
event_0CD_command_1AD7:
    event_call 247
event_0CD_command_1AD9:
    event_jump 1561
event_0CD_command_1ADB:
    event_end 
event_0CE_command_1ADC:
    event_test_flag_range 30, 7, 15
event_0CE_command_1ADF:
    event_jump 209
event_0CE_command_1AE1:
    event_test_flag_range 17, 0, 0
event_0CE_command_1AE4:
    event_jump 251
event_0CE_command_1AE6:
    event_set_flag 15, 0
event_0CE_command_1AE9:
    event_call 1032
