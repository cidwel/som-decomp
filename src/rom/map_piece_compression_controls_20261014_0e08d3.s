.setcpu "65816"
.segment "CODE"
.org $08D3
map_control_0e08d3:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
