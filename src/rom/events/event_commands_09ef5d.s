; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EF5D
.include "src/rom/event_command_macros.inc"
event_3E6_command_EF5D:
    event_jump 1535
event_3E6_command_EF5F:
    event_end 
