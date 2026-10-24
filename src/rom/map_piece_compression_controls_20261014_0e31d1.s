.setcpu "65816"
.segment "CODE"
.org $31D1
map_control_0e31d1:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
