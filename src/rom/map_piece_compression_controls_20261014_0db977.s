.setcpu "65816"
.segment "CODE"
.org $B977
map_control_0db977:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
