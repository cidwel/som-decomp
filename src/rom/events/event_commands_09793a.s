; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $793A
.include "src/rom/event_command_macros.inc"
event_1D2_command_793A:
    event_set_flag 88, 0
event_1D2_command_793D:
    event_return 
event_1D2_command_793E:
    event_end 
event_1D3_command_793F:
    event_test_actor 1
event_1D3_command_7941:
    event_jump 477
