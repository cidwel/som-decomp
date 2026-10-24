.setcpu "65816"
.segment "CODE"
.org $4623
map_control_0e4623:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
