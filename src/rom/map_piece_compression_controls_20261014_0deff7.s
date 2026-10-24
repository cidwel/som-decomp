.setcpu "65816"
.segment "CODE"
.org $EFF7
map_control_0deff7:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
