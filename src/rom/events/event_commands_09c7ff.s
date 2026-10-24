; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C7FF
.include "src/rom/event_command_macros.inc"
event_2EC_command_C7FF:
    event_jump 1535
event_2EC_command_C801:
    event_end 
