; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E98F
.include "src/rom/event_command_macros.inc"
event_3CE_command_E98F:
    event_jump 1535
event_3CE_command_E991:
    event_end 
