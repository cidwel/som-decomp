; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B423
.include "src/rom/event_command_macros.inc"
event_2A0_command_B423:
    event_jump 1535
event_2A0_command_B425:
    event_end 
event_2A1_command_B426:
    event_call 1284
event_2A1_command_B428:
    event_call 1994
event_2A1_command_B42A:
    event_set_flag 40, 12
event_2A1_command_B42D:
    event_change_map 511
event_2A1_command_B42F:
    event_end 
