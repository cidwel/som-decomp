; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A675
.include "src/rom/event_command_macros.inc"
event_275_command_A675:
    event_jump 1535
event_275_command_A677:
    event_end 
