; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9681
.include "src/rom/event_command_macros.inc"
event_21E_command_9681:
    event_wait 0
