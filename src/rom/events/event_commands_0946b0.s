; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $46B0
.include "src/rom/event_command_macros.inc"
event_147_command_46B0:
    event_jump 1535
event_147_command_46B2:
    event_end 
event_148_command_46B3:
    event_test_flag_range 13, 1, 1
event_148_command_46B6:
    event_jump 333
