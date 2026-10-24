; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A267
.include "src/rom/event_command_macros.inc"
event_25F_command_A267:
    event_jump 1535
event_25F_command_A269:
    event_end 
event_260_command_A26A:
    event_jump 1564
event_260_command_A26C:
    event_end 
event_261_command_A26D:
    event_jump 1251
event_261_command_A26F:
    event_end 
