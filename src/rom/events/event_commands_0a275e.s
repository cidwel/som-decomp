; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $275E
.include "src/rom/event_command_macros.inc"
event_4CA_command_275E:
    event_wait 0
