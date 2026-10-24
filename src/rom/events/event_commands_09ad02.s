; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AD02
.include "src/rom/event_command_macros.inc"
event_290_command_AD02:
    event_jump 1535
event_290_command_AD04:
    event_end 
event_291_command_AD05:
    event_test_flag_range 40, 2, 3
event_291_command_AD08:
    event_jump 658
event_291_command_AD0A:
    event_test_flag_range 40, 4, 15
event_291_command_AD0D:
    event_jump 660
