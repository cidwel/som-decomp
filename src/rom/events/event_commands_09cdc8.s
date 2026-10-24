; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CDC8
.include "src/rom/event_command_macros.inc"
event_318_command_CDC8:
    event_jump 255
event_318_command_CDCA:
    event_jump 79
event_318_command_CDCC:
    event_jump 786
event_318_command_CDCE:
    event_jump 787
event_318_command_CDD0:
    event_end 
