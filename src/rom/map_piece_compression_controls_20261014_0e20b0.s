.setcpu "65816"
.segment "CODE"
.org $20B0
map_control_0e20b0:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
