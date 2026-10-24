; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $98DE
.include "src/rom/event_command_macros.inc"
event_7FF_command_98DE:
    event_party_command 7
event_7FF_command_98E0:
    event_end 
