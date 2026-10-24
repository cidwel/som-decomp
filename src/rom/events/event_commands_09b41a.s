; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B41A
.include "src/rom/event_command_macros.inc"
event_29F_command_B41A:
    event_jump 1535
event_29F_command_B41C:
    event_end 
