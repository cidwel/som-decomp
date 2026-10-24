.setcpu "65816"
.segment "CODE"
.org $99D3
map_control_0e99d3:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
