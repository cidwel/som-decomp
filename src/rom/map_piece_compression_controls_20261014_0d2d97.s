.setcpu "65816"
.segment "CODE"
.org $2D97
map_control_0d2d97:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
