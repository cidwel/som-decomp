; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C14F
.include "src/rom/event_command_macros.inc"
event_2D4_command_C14F:
    event_jump 720
event_2D4_command_C151:
    event_end 
event_2D5_command_C152:
    event_test_flag_range 60, 6, 15
event_2D5_command_C155:
    event_jump 727
