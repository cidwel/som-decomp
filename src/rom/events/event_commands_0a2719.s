; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2719
.include "src/rom/event_command_macros.inc"
event_4CA_command_2719:
    event_wait 0
