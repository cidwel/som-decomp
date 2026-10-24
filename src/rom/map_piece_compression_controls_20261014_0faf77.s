.setcpu "65816"
.segment "CODE"
.org $AF77
map_control_0faf77:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E3 ; previous-row copy count
