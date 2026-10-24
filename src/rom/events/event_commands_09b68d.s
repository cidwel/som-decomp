; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B68D
.include "src/rom/event_command_macros.inc"
event_2AD_command_B68D:
    event_jump 1535
event_2AD_command_B68F:
    event_end 
