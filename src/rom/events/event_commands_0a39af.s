; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $39AF
.include "src/rom/event_command_macros.inc"
event_4E4_command_39AF:
    event_wait 0
