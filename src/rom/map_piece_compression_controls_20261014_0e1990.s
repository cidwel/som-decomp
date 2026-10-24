.setcpu "65816"
.segment "CODE"
.org $1990
map_control_0e1990:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
