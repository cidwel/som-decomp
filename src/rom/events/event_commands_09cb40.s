; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CB40
.include "src/rom/event_command_macros.inc"
event_2FC_command_CB40:
    event_jump 1809
event_2FC_command_CB42:
    event_end 
