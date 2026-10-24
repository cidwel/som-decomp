; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E8B9
.include "src/rom/event_command_macros.inc"
event_3CB_command_E8B9:
    event_jump 1535
event_3CB_command_E8BB:
    event_end 
