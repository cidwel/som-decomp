; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8AA1
.include "src/rom/event_command_macros.inc"
event_66B_command_8AA1:
    event_end 
event_66B_command_8AA2:
    event_end 
event_66B_command_8AA3:
    event_jump 1646
event_66B_command_8AA5:
    event_jump 1644
event_66B_command_8AA7:
    event_end 
event_66C_command_8AA8:
    event_increment_flag 248
