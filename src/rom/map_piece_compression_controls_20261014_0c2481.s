.setcpu "65816"
.segment "CODE"
.org $2481
map_control_0c2481:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
