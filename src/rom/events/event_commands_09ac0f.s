; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AC0F
.include "src/rom/event_command_macros.inc"
event_28C_command_AC0F:
    event_jump 651
event_28C_command_AC11:
    event_end 
event_28D_command_AC12:
    event_test_flag_range 40, 0, 2
event_28D_command_AC15:
    event_jump 684
event_28D_command_AC17:
    event_test_flag_range 40, 3, 3
event_28D_command_AC1A:
    event_jump 659
