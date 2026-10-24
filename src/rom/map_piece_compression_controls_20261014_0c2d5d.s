.setcpu "65816"
.segment "CODE"
.org $2D5D
map_control_0c2d5d:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
