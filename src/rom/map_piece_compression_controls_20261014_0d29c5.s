.setcpu "65816"
.segment "CODE"
.org $29C5
map_control_0d29c5:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
