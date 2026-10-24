; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $862F
.include "src/rom/event_command_macros.inc"
event_605_command_862F:
    event_jump 1535
event_605_command_8631:
    event_end 
