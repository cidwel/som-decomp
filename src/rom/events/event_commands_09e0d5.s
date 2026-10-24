; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E0D5
.include "src/rom/event_command_macros.inc"
event_3A4_command_E0D5:
    event_jump 1456
event_3A4_command_E0D7:
    event_end 
