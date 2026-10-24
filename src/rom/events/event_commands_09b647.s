; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B647
.include "src/rom/event_command_macros.inc"
event_2AA_command_B647:
    event_jump 0
event_2AA_command_B649:
    event_party_command 6
event_2AA_command_B64B:
    event_jump 0
event_2AA_command_B64D:
    event_end 
event_2AB_command_B64E:
    event_call 1994
event_2AB_command_B650:
    event_end 
