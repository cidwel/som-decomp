.setcpu "65816"
.segment "CODE"
.org $B59F
map_control_0db59f:
    .byte $E0 ; previous-row copy escape
    .byte $40 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E3 ; previous-row copy count
