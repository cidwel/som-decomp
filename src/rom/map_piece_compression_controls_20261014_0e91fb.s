.setcpu "65816"
.segment "CODE"
.org $91FB
map_control_0e91fb:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
