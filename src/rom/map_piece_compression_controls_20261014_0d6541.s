.setcpu "65816"
.segment "CODE"
.org $6541
map_control_0d6541:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
