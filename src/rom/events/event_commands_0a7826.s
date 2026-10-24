; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7826
.include "src/rom/event_command_macros.inc"
event_5B1_command_7826:
    event_jump 1535
event_5B1_command_7828:
    event_end 
event_5B2_command_7829:
    event_test_flag_range 90, 1, 15
event_5B2_command_782C:
    event_jump 1457
event_5B2_command_782E:
    event_increment_flag 90
