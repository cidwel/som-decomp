; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1DC8
.include "src/rom/event_command_macros.inc"
event_4AC_command_1DC8:
    event_increment_flag 65
event_4AC_command_1DCA:
    event_jump 1195
event_4AC_command_1DCC:
    event_end 
