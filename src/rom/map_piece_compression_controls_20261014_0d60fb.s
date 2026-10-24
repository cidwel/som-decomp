.setcpu "65816"
.segment "CODE"
.org $60FB
map_control_0d60fb:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
