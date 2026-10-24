.setcpu "65816"
.segment "CODE"
.org $29AD
map_control_0d29ad:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
