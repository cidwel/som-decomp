.setcpu "65816"
.segment "CODE"
.org $3896
map_control_0e3896:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
