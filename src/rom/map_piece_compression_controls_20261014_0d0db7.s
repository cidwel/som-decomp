.setcpu "65816"
.segment "CODE"
.org $0DB7
map_control_0d0db7:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
