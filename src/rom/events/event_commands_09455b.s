; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $455B
.include "src/rom/event_command_macros.inc"
event_144_command_455B:
    event_jump 1535
event_144_command_455D:
    event_end 
