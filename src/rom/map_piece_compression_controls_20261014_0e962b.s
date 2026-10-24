.setcpu "65816"
.segment "CODE"
.org $962B
map_control_0e962b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
