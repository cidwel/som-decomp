; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EC85
.include "src/rom/event_command_macros.inc"
event_3DB_command_EC85:
    event_decrement_flag 248
event_3DB_command_EC87:
    event_end 
