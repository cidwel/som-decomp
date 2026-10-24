; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5136
.include "src/rom/event_command_macros.inc"
event_16D_command_5136:
    event_call 1944
event_16D_command_5138:
    event_increment_flag 26
event_16D_command_513A:
    event_redraw_pieces 
event_16D_command_513B:
    event_toggle_visibility_04 
event_16D_command_513C:
    event_wait 0
event_16D_command_513E:
    event_change_map 50
event_16D_command_5140:
    event_increment_flag 255
event_16D_command_5142:
    event_call 247
