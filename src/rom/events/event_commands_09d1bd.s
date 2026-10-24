; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D1BD
.include "src/rom/event_command_macros.inc"
event_35F_command_D1BD:
    event_jump 864
event_35F_command_D1BF:
    event_end 
