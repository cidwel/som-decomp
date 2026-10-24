.setcpu "65816"
.segment "CODE"
.org $FE5F
map_control_0dfe5f:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
