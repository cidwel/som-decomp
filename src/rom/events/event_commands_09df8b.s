; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DF8B
.include "src/rom/event_command_macros.inc"
event_39B_command_DF8B:
    event_jump 1535
event_39B_command_DF8D:
    event_end 
