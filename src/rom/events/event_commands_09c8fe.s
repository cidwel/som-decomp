; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C8FE
.include "src/rom/event_command_macros.inc"
event_2F4_command_C8FE:
    event_jump 1535
event_2F4_command_C900:
    event_end 
