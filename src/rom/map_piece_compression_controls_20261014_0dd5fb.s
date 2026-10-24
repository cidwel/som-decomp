.setcpu "65816"
.segment "CODE"
.org $D5FB
map_control_0dd5fb:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
