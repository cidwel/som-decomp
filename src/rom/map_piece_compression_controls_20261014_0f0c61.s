.setcpu "65816"
.segment "CODE"
.org $0C61
map_control_0f0c61:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
