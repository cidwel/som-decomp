; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6186
.include "src/rom/event_command_macros.inc"
event_19A_command_6186:
    event_jump 1535
event_19A_command_6188:
    event_end 
