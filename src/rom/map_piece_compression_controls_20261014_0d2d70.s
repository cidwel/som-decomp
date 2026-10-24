.setcpu "65816"
.segment "CODE"
.org $2D70
map_control_0d2d70:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
