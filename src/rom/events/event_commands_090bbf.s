; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0BBF
.include "src/rom/event_command_macros.inc"
event_026_command_0BBF:
    event_jump 1535
event_026_command_0BC1:
    event_end 
