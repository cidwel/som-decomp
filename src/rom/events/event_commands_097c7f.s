; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7C7F
.include "src/rom/event_command_macros.inc"
event_1D6_command_7C7F:
    event_end 
event_1D6_command_7C80:
    event_end 
event_1D6_command_7C81:
    event_jump 469
event_1D6_command_7C83:
    event_jump 470
event_1D6_command_7C85:
    event_end 
