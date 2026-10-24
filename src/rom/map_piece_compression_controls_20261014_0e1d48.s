.setcpu "65816"
.segment "CODE"
.org $1D48
map_control_0e1d48:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
