.setcpu "65816"
.segment "CODE"
.org $F315
map_control_0cf315:
    .byte $F5 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $18 ; distance low bit/count
