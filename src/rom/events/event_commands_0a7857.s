; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7857
.include "src/rom/event_command_macros.inc"
event_5B3_command_7857:
    event_jump 1456
event_5B3_command_7859:
    event_end 
event_5B4_command_785A:
    event_test_flag_range 90, 0, 1
event_5B4_command_785D:
    event_jump 1457
event_5B4_command_785F:
    event_increment_flag 90
