.setcpu "65816"
.segment "CODE"
.org $B6FB
map_control_0db6fb:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E3 ; previous-row copy count
