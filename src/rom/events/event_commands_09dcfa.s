; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DCFA
.include "src/rom/event_command_macros.inc"
event_393_command_DCFA:
    event_jump 1535
event_393_command_DCFC:
    event_end 
event_394_command_DCFD:
    event_end 
event_395_command_DCFE:
    event_end 
