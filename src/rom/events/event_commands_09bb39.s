; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BB39
.include "src/rom/event_command_macros.inc"
event_2BB_command_BB39:
    event_jump 1535
event_2BB_command_BB3B:
    event_end 
