; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AFDE
.include "src/rom/event_command_macros.inc"
event_297_command_AFDE:
    event_jump 1535
event_297_command_AFE0:
    event_end 
event_298_command_AFE1:
    event_call 665
event_298_command_AFE3:
    event_end 
