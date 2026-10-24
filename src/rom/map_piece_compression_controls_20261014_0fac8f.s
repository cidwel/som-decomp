.setcpu "65816"
.segment "CODE"
.org $AC8F
map_control_0fac8f:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
