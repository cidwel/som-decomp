; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5D5F
.include "src/rom/event_command_macros.inc"
event_190_command_5D5F:
    event_jump 1535
event_190_command_5D61:
    event_end 
event_191_command_5D62:
    event_test_flag_range 18, 9, 15
event_191_command_5D65:
    event_jump 413
