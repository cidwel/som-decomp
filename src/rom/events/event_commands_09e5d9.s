; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E5D9
.include "src/rom/event_command_macros.inc"
event_3BB_command_E5D9:
    event_jump 1535
event_3BB_command_E5DB:
    event_end 
