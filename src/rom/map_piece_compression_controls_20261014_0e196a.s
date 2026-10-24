.setcpu "65816"
.segment "CODE"
.org $196A
map_control_0e196a:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
