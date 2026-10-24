.setcpu "65816"
.segment "CODE"
.org $3564
map_control_0d3564:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
