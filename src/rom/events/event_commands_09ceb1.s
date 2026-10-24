; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CEB1
.include "src/rom/event_command_macros.inc"
event_330_command_CEB1:
    event_return 
event_330_command_CEB2:
    event_end 
