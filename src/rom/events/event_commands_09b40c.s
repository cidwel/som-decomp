; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B40C
.include "src/rom/event_command_macros.inc"
event_29E_command_B40C:
    event_decrement_flag 255
event_29E_command_B40E:
    event_end 
