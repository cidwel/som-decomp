.setcpu "65816"
.segment "CODE"
.org $30B8
map_control_0c30b8:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $6E ; row-distance/count
