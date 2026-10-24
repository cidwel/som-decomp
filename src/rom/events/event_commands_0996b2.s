; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $96B2
.include "src/rom/event_command_macros.inc"
event_21E_command_96B2:
    event_jump 1535
event_21E_command_96B4:
    event_end 
