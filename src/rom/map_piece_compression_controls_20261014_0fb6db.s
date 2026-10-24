.setcpu "65816"
.segment "CODE"
.org $B6DB
map_control_0fb6db:
    .byte $E9 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
