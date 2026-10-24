; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A4B8
.include "src/rom/event_command_macros.inc"
event_269_command_A4B8:
    event_jump 1535
event_269_command_A4BA:
    event_end 
