.setcpu "65816"
.segment "CODE"
.org $CFE8
map_control_0ecfe8:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
