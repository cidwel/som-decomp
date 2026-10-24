; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7154
.include "src/rom/event_command_macros.inc"
event_1C5_command_7154:
    event_end 
event_1C5_command_7155:
    event_end 
event_1C5_command_7156:
    event_jump 454
event_1C5_command_7158:
    event_change_map 55
event_1C5_command_715A:
    event_jump 1797
event_1C5_command_715C:
    event_unfreeze 
event_1C5_command_715D:
    event_end 
