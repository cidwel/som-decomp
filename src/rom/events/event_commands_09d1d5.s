; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D1D5
.include "src/rom/event_command_macros.inc"
event_360_command_D1D5:
    event_jump 1535
event_360_command_D1D7:
    event_end 
event_361_command_D1D8:
    event_end 
event_362_command_D1D9:
    event_end 
