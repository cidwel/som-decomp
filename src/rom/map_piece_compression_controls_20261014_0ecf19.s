.setcpu "65816"
.segment "CODE"
.org $CF19
map_control_0ecf19:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
