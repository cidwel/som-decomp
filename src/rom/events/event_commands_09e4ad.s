; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E4AD
.include "src/rom/event_command_macros.inc"
event_3B4_command_E4AD:
    event_jump 1535
event_3B4_command_E4AF:
    event_end 
