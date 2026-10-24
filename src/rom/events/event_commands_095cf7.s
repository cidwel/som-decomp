; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5CF7
.include "src/rom/event_command_macros.inc"
event_18E_command_5CF7:
    event_jump 1535
event_18E_command_5CF9:
    event_end 
