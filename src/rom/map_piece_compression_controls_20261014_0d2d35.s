.setcpu "65816"
.segment "CODE"
.org $2D35
map_control_0d2d35:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
