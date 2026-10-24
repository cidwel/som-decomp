.setcpu "65816"
.segment "CODE"
.org $20B3
map_control_0e20b3:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
