; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E457
.include "src/rom/event_command_macros.inc"
event_3B2_command_E457:
    event_jump 1535
event_3B2_command_E459:
    event_end 
