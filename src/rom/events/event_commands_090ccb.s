; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0CCB
.include "src/rom/event_command_macros.inc"
event_02B_command_0CCB:
    event_jump 1535
event_02B_command_0CCD:
    event_end 
