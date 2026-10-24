; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0BAA
.include "src/rom/event_command_macros.inc"
event_025_command_0BAA:
    event_call 1051
event_025_command_0BAC:
    event_restore_hero 132
event_025_command_0BAE:
    event_end 
