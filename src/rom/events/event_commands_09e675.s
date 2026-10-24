; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E675
.include "src/rom/event_command_macros.inc"
event_3C0_command_E675:
    event_jump 1535
event_3C0_command_E677:
    event_end 
