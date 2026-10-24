.setcpu "65816"
.segment "CODE"
.org $2D47
map_control_0c2d47:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
