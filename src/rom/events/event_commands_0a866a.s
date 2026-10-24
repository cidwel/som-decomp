; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $866A
.include "src/rom/event_command_macros.inc"
event_607_command_866A:
    event_jump 1535
event_607_command_866C:
    event_end 
