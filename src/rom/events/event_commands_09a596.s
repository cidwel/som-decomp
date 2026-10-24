; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A596
.include "src/rom/event_command_macros.inc"
event_26F_command_A596:
    event_jump 1535
event_26F_command_A598:
    event_end 
