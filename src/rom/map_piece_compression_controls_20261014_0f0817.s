.setcpu "65816"
.segment "CODE"
.org $0817
map_control_0f0817:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
