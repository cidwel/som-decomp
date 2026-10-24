.setcpu "65816"
.segment "CODE"
.org $2D98
map_control_0c2d98:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
