; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D6F9
.include "src/rom/event_command_macros.inc"
event_371_command_D6F9:
    event_jump 1535
event_371_command_D6FB:
    event_end 
