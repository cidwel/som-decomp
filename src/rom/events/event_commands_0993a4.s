; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $93A4
.include "src/rom/event_command_macros.inc"
event_211_command_93A4:
    event_return 
event_211_command_93A5:
    event_end 
event_212_command_93A6:
    event_test_flag_range 89, 1, 15
event_212_command_93A9:
    event_jump 531
