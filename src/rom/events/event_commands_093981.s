; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3981
.include "src/rom/event_command_macros.inc"
event_121_command_3981:
    event_set_flag 17, 1
event_121_command_3984:
    event_end 
event_122_command_3985:
    event_test_flag_range 84, 1, 15
event_122_command_3988:
    event_jump 288
