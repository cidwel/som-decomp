; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $75B7
.include "src/rom/event_command_macros.inc"
event_1CD_command_75B7:
    event_set_flag 21, 0
event_1CD_command_75BA:
    event_change_map 86
event_1CD_command_75BC:
    event_jump 1823
event_1CD_command_75BE:
    event_end 
event_1CE_command_75BF:
    event_call 94
event_1CE_command_75C1:
    event_set_flag 15, 0
event_1CE_command_75C4:
    event_object_command_37 50
