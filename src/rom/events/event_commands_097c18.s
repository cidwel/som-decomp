; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7C18
.include "src/rom/event_command_macros.inc"
event_1D4_command_7C18:
    event_set_flag 96, 9
event_1D4_command_7C1B:
    event_increment_flag 24
event_1D4_command_7C1D:
    event_change_map 82
event_1D4_command_7C1F:
    event_jump 1823
event_1D4_command_7C21:
    event_end 
event_1D5_command_7C22:
    event_call 94
