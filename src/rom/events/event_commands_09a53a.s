; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A53A
.include "src/rom/event_command_macros.inc"
event_26D_command_A53A:
    event_jump 1535
event_26D_command_A53C:
    event_end 
