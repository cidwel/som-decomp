; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D895
.include "src/rom/event_command_macros.inc"
event_37C_command_D895:
    event_test_flag_range 38, 0, 0
event_37C_command_D898:
    event_increment_flag 38
event_37C_command_D89A:
    event_end 
