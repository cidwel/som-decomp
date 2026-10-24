; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BFBB
.include "src/rom/event_command_macros.inc"
event_2D3_command_BFBB:
    event_jump 1535
event_2D3_command_BFBD:
    event_end 
event_2D4_command_BFBE:
    event_call 1151
