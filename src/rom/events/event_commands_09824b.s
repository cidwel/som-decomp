; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $824B
.include "src/rom/event_command_macros.inc"
event_1E3_command_824B:
    event_jump 1535
event_1E3_command_824D:
    event_end 
event_1E4_command_824E:
    event_call 1939
event_1E4_command_8250:
    event_change_map 80
event_1E4_command_8252:
    event_end 
