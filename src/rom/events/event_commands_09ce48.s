; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CE48
.include "src/rom/event_command_macros.inc"
event_321_command_CE48:
    event_jump 817
event_321_command_CE4A:
    event_end 
event_322_command_CE4B:
    event_set_flag 249, 2
event_322_command_CE4E:
    event_call 816
