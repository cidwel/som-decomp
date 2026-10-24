; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $195B
.include "src/rom/event_command_macros.inc"
event_0BA_command_195B:
    event_jump 1535
event_0BA_command_195D:
    event_end 
