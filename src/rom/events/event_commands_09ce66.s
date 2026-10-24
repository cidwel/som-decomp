; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CE66
.include "src/rom/event_command_macros.inc"
event_324_command_CE66:
    event_jump 817
event_324_command_CE68:
    event_end 
event_325_command_CE69:
    event_set_flag 249, 5
event_325_command_CE6C:
    event_call 816
