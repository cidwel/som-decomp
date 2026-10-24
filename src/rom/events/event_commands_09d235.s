; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D235
.include "src/rom/event_command_macros.inc"
event_363_command_D235:
    event_jump 1535
event_363_command_D237:
    event_end 
