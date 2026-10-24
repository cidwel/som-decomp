.setcpu "65816"
.segment "CODE"
.org $2D05
map_control_0d2d05:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
