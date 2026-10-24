; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7101
.include "src/rom/event_command_macros.inc"
event_1C4_command_7101:
    event_jump 1535
event_1C4_command_7103:
    event_end 
