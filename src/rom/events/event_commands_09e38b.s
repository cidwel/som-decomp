; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E38B
.include "src/rom/event_command_macros.inc"
event_3AD_command_E38B:
    event_jump 1535
event_3AD_command_E38D:
    event_end 
