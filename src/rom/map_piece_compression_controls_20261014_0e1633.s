.setcpu "65816"
.segment "CODE"
.org $1633
map_control_0e1633:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
