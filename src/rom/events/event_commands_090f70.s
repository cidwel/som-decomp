; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0F70
.include "src/rom/event_command_macros.inc"
event_040_command_0F70:
    event_party_command 1
