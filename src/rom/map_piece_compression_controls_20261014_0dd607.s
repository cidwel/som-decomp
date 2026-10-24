.setcpu "65816"
.segment "CODE"
.org $D607
map_control_0dd607:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
