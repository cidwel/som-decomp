; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $88E3
.include "src/rom/event_command_macros.inc"
event_1ED_command_88E3:
    event_increment_flag 216
event_1ED_command_88E5:
    event_increment_flag 217
event_1ED_command_88E7:
    event_refresh_objects 
event_1ED_command_88E8:
    event_call 490
event_1ED_command_88EA:
    event_test_flag_range 24, 1, 1
event_1ED_command_88ED:
    event_jump 501
