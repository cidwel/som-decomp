; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $870C
.include "src/rom/event_command_macros.inc"
event_1EA_command_870C:
    event_wait 0
event_1EA_command_870E:
    event_return 
event_1EA_command_870F:
    event_end 
