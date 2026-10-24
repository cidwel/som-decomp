.setcpu "65816"
.segment "CODE"
.org $0F6F
map_control_0c0f6f:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
