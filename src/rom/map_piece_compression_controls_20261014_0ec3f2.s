.setcpu "65816"
.segment "CODE"
.org $C3F2
map_control_0ec3f2:
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
