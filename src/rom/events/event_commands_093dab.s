; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3DAB
.include "src/rom/event_command_macros.inc"
event_135_command_3DAB:
    event_jump 1535
event_135_command_3DAD:
    event_end 
event_136_command_3DAE:
    event_test_flag_range 17, 12, 12
event_136_command_3DB1:
    event_jump 311
event_136_command_3DB3:
    event_test_flag_range 17, 13, 13
event_136_command_3DB6:
    event_jump 312
event_136_command_3DB8:
    event_test_flag_range 17, 14, 14
event_136_command_3DBB:
    event_jump 319
