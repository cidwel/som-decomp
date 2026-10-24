; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EEDC
.include "src/rom/event_command_macros.inc"
event_3E4_command_EEDC:
    event_jump 1535
event_3E4_command_EEDE:
    event_end 
