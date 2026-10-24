.setcpu "65816"
.segment "CODE"
.org $23FB
map_control_0d23fb:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
