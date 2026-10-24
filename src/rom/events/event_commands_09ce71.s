; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CE71
.include "src/rom/event_command_macros.inc"
event_325_command_CE71:
    event_jump 817
event_325_command_CE73:
    event_end 
event_326_command_CE74:
    event_set_flag 249, 6
event_326_command_CE77:
    event_call 816
