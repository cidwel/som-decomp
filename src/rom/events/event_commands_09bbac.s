; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BBAC
.include "src/rom/event_command_macros.inc"
event_2BD_command_BBAC:
    event_jump 1535
event_2BD_command_BBAE:
    event_end 
