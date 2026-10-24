.setcpu "65816"
.segment "CODE"
.org $5D5F
map_control_0c5d5f:
    .byte $F2 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
