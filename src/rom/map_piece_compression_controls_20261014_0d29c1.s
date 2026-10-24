.setcpu "65816"
.segment "CODE"
.org $29C1
map_control_0d29c1:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
