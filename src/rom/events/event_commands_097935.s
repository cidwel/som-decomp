; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7935
.include "src/rom/event_command_macros.inc"
event_1D1_command_7935:
    event_end 
event_1D2_command_7936:
    event_object_command_36 100
