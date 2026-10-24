.setcpu "65816"
.segment "CODE"
.org $2D7D
map_control_0c2d7d:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
