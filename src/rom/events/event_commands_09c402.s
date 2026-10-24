; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C402
.include "src/rom/event_command_macros.inc"
event_2DA_command_C402:
    event_jump 1535
event_2DA_command_C404:
    event_end 
