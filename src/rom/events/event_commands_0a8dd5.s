; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8DD5
.include "src/rom/event_command_macros.inc"
event_66D_command_8DD5:
    event_increment_flag 38
event_66D_command_8DD7:
    event_change_map 512
event_66D_command_8DD9:
    event_jump 1590
event_66D_command_8DDB:
    event_end 
event_66E_command_8DDC:
    event_increment_flag 248
