.setcpu "65816"
.segment "CODE"
.org $1D44
map_control_0e1d44:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
