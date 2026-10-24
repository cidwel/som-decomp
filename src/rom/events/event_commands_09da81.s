; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DA81
.include "src/rom/event_command_macros.inc"
event_38C_command_DA81:
    event_wait 16
event_38C_command_DA83:
    event_call 1929
event_38C_command_DA85:
    event_wait 4
event_38C_command_DA87:
    event_call 1929
event_38C_command_DA89:
    event_wait 24
