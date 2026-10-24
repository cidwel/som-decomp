; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5BE1
.include "src/rom/event_command_macros.inc"
event_18A_command_5BE1:
    event_jump 1535
event_18A_command_5BE3:
    event_end 
