; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CE5C
.include "src/rom/event_command_macros.inc"
event_323_command_CE5C:
    event_jump 817
event_323_command_CE5E:
    event_end 
event_324_command_CE5F:
    event_set_flag 249, 4
event_324_command_CE62:
    event_call 816
