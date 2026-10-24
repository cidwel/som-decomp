; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $975C
.include "src/rom/event_command_macros.inc"
event_223_command_975C:
    event_jump 1535
event_223_command_975E:
    event_end 
