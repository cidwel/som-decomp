.setcpu "65816"
.segment "CODE"
.org $2D4E
map_control_0c2d4e:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
