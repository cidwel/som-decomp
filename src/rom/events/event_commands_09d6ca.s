; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D6CA
.include "src/rom/event_command_macros.inc"
event_370_command_D6CA:
    event_jump 1535
event_370_command_D6CC:
    event_end 
