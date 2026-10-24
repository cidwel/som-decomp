.setcpu "65816"
.segment "CODE"
.org $E9BE
map_control_0fe9be:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
