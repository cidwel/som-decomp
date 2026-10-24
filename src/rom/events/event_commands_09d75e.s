; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D75E
.include "src/rom/event_command_macros.inc"
event_374_command_D75E:
    event_jump 1535
event_374_command_D760:
    event_end 
event_375_command_D761:
    event_call 1152
