.setcpu "65816"
.segment "CODE"
.org $4D45
map_control_0e4d45:
    .byte $F2 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
