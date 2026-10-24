; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $45F9
.include "src/rom/event_command_macros.inc"
event_146_command_45F9:
    event_jump 1535
event_146_command_45FB:
    event_end 
