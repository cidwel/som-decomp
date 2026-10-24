.setcpu "65816"
.segment "CODE"
.org $53FE
map_control_0f53fe:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
