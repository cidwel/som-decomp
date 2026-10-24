.setcpu "65816"
.segment "CODE"
.org $F17F
map_control_0ef17f:
    .byte $E5 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
