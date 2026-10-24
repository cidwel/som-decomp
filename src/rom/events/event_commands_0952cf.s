; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $52CF
.include "src/rom/event_command_macros.inc"
event_170_command_52CF:
    event_jump 1535
event_170_command_52D1:
    event_end 
