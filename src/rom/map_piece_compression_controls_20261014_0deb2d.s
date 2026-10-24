.setcpu "65816"
.segment "CODE"
.org $EB2D
map_control_0deb2d:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
