.setcpu "65816"
.segment "CODE"
.org $B468
map_control_0eb468:
    .byte $F1 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $90 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
