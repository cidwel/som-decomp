.setcpu "65816"
.segment "CODE"
.org $11C2
map_control_0d11c2:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
