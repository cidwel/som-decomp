; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $21C1
.include "src/rom/event_command_macros.inc"
event_4B4_command_21C1:
    event_decrement_flag 248
event_4B4_command_21C3:
    event_set_flag 74, 1
event_4B4_command_21C6:
    event_call 2009
event_4B4_command_21C8:
    event_change_map 840
