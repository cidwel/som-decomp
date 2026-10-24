.setcpu "65816"
.segment "CODE"
.org $0F7D
map_control_0c0f7d:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
