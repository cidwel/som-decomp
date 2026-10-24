.setcpu "65816"
.segment "CODE"
.org $75D3
map_control_0e75d3:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
