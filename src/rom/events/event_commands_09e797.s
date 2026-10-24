; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E797
.include "src/rom/event_command_macros.inc"
event_3C5_command_E797:
    event_jump 1535
event_3C5_command_E799:
    event_end 
