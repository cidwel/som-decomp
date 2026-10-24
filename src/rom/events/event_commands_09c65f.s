; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C65F
.include "src/rom/event_command_macros.inc"
event_2E4_command_C65F:
    event_jump 1535
event_2E4_command_C661:
    event_end 
event_2E5_command_C662:
    event_test_flag_range 60, 0, 3
event_2E5_command_C665:
    event_jump 735
