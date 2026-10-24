; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E872
.include "src/rom/event_command_macros.inc"
event_3C9_command_E872:
    event_jump 1535
event_3C9_command_E874:
    event_end 
