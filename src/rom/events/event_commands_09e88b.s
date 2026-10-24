; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E88B
.include "src/rom/event_command_macros.inc"
event_3CA_command_E88B:
    event_jump 1535
event_3CA_command_E88D:
    event_end 
