; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C988
.include "src/rom/event_command_macros.inc"
event_2F7_command_C988:
    event_jump 1535
event_2F7_command_C98A:
    event_end 
