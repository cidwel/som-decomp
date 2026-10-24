; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DA30
.include "src/rom/event_command_macros.inc"
event_388_command_DA30:
    event_jump 1535
event_388_command_DA32:
    event_end 
