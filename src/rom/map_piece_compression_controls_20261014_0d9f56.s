.setcpu "65816"
.segment "CODE"
.org $9F56
map_control_0d9f56:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
