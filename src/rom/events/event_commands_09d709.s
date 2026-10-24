; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D709
.include "src/rom/event_command_macros.inc"
event_372_command_D709:
    event_jump 1535
event_372_command_D70B:
    event_end 
