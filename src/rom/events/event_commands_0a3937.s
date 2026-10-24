; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3937
.include "src/rom/event_command_macros.inc"
event_4E4_command_3937:
    event_call 1947
event_4E4_command_3939:
    event_wait 16
event_4E4_command_393B:
    event_call 2008
event_4E4_command_393D:
    event_wait 16
event_4E4_command_393F:
    event_wait 0
