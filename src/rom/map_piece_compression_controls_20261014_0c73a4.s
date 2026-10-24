.setcpu "65816"
.segment "CODE"
.org $73A4
map_control_0c73a4:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
