.setcpu "65816"
.segment "CODE"
.org $20B6
map_control_0e20b6:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
