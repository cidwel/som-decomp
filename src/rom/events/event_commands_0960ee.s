; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $60EE
.include "src/rom/event_command_macros.inc"
event_198_command_60EE:
    event_wait 0
