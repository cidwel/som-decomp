; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CE52
.include "src/rom/event_command_macros.inc"
event_322_command_CE52:
    event_jump 817
event_322_command_CE54:
    event_end 
event_323_command_CE55:
    event_set_flag 249, 3
event_323_command_CE58:
    event_call 816
