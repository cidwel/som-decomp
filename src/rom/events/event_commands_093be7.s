; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3BE7
.include "src/rom/event_command_macros.inc"
event_12F_command_3BE7:
    event_jump 1535
event_12F_command_3BE9:
    event_end 
event_130_command_3BEA:
    event_test_flag_range 17, 9, 9
event_130_command_3BED:
    event_jump 306
event_130_command_3BEF:
    event_test_flag_range 17, 10, 10
event_130_command_3BF2:
    event_jump 307
event_130_command_3BF4:
    event_test_flag_range 17, 11, 15
event_130_command_3BF7:
    event_jump 308
