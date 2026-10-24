.setcpu "65816"
.segment "CODE"
.org $2654
map_control_0e2654:
    .byte $F3 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
