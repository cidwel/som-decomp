; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $269D
.include "src/rom/event_command_macros.inc"
event_103_command_269D:
    event_wait 16
event_103_command_269F:
    event_increment_flag 16
event_103_command_26A1:
    event_refresh_objects 
event_103_command_26A2:
    event_increment_flag 0
event_103_command_26A4:
    event_set_actor_field 0, 144, 0
