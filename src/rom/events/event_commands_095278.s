; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5278
.include "src/rom/event_command_macros.inc"
event_16E_command_5278:
    event_decrement_flag 248
event_16E_command_527A:
    event_change_map 48
event_16E_command_527C:
    event_end 
