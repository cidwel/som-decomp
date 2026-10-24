.setcpu "65816"
.segment "CODE"
.org $2541
map_control_0c2541:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
