.setcpu "65816"
.segment "CODE"
.org $F2D7
map_control_0df2d7:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
