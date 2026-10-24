.setcpu "65816"
.segment "CODE"
.org $B0AA
map_control_0fb0aa:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E6 ; previous-row copy count
