.setcpu "65816"
.segment "CODE"
.org $8AFE
map_control_0f8afe:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
