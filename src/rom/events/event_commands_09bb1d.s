; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BB1D
.include "src/rom/event_command_macros.inc"
event_2BA_command_BB1D:
    event_jump 1535
event_2BA_command_BB1F:
    event_end 
