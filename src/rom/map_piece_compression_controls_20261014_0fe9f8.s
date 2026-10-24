.setcpu "65816"
.segment "CODE"
.org $E9F8
map_control_0fe9f8:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
