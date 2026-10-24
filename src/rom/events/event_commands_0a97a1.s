; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $97A1
.include "src/rom/event_command_macros.inc"
event_7FA_command_97A1:
    event_return 
event_7FA_command_97A2:
    event_end 
event_7FB_command_97A3:
    event_test_flag_range 13, 0, 0
event_7FB_command_97A6:
    event_jump 2042
