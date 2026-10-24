.setcpu "65816"
.segment "CODE"
.org $1E4D
map_control_0e1e4d:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
