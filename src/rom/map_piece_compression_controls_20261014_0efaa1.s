.setcpu "65816"
.segment "CODE"
.org $FAA1
map_control_0efaa1:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
