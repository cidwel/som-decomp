; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $62FE
.include "src/rom/event_command_macros.inc"
event_1A1_command_62FE:
    event_jump 1535
event_1A1_command_6300:
    event_end 
