.setcpu "65816"
.segment "CODE"
.org $0C84
map_control_0c0c84:
    .byte $E8 ; backreference distance high bits
    .byte $68 ; distance low bit/count
