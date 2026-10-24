; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $46E7
.include "src/rom/event_command_macros.inc"
event_148_command_46E7:
    event_jump 1535
event_148_command_46E9:
    event_end 
event_149_command_46EA:
    event_test_flag_range 13, 1, 1
event_149_command_46ED:
    event_jump 346
