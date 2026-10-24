; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $091F
.include "src/rom/event_command_macros.inc"
event_012_command_091F:
    event_return 
event_012_command_0920:
    event_end 
event_013_command_0921:
    event_wait 0
