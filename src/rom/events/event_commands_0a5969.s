; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5969
.include "src/rom/event_command_macros.inc"
event_506_command_5969:
    event_jump 1289
event_506_command_596B:
    event_end 
event_507_command_596C:
    event_test_flag_range 191, 9, 15
event_507_command_596F:
    event_jump 1288
event_507_command_5971:
    event_increment_flag 191
event_507_command_5973:
    event_test_flag_range 199, 0, 8
event_507_command_5976:
    event_increment_flag 199
