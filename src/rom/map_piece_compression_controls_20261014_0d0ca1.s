.setcpu "65816"
.segment "CODE"
.org $0CA1
map_control_0d0ca1:
    .byte $EB ; backreference distance high bits
    .byte $8C ; distance low bit/count
