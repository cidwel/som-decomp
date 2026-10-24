.setcpu "65816"
.segment "CODE"
.org $5B1D
map_control_0d5b1d:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
