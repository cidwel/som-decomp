; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0FE9
.include "src/rom/event_command_macros.inc"
event_041_command_0FE9:
    event_party_command 2
