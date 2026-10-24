; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CCAC
.include "src/rom/event_command_macros.inc"
event_310_command_CCAC:
    event_jump 785
event_310_command_CCAE:
    event_jump 786
event_310_command_CCB0:
    event_jump 787
event_310_command_CCB2:
    event_end 
event_311_command_CCB3:
    event_test_flag_range 16, 10, 10
event_311_command_CCB6:
    event_call 213
