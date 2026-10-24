; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1DD9
.include "src/rom/event_command_macros.inc"
event_4AD_command_1DD9:
    event_jump 1535
event_4AD_command_1DDB:
    event_end 
