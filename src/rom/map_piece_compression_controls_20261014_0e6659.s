.setcpu "65816"
.segment "CODE"
.org $6659
map_control_0e6659:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
