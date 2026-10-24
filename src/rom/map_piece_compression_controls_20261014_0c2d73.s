.setcpu "65816"
.segment "CODE"
.org $2D73
map_control_0c2d73:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
