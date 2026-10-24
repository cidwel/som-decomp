; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1F83
.include "src/rom/event_command_macros.inc"
event_0E5_command_1F83:
    event_end 
event_0E6_command_1F84:
    event_object_command_37 50
