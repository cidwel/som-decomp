.setcpu "65816"
.segment "CODE"
.org $2D63
map_control_0c2d63:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
