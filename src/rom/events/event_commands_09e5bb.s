; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E5BB
.include "src/rom/event_command_macros.inc"
event_3BA_command_E5BB:
    event_jump 1535
event_3BA_command_E5BD:
    event_end 
