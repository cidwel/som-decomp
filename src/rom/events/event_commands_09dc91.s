; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DC91
.include "src/rom/event_command_macros.inc"
event_390_command_DC91:
    event_jump 1535
event_390_command_DC93:
    event_end 
