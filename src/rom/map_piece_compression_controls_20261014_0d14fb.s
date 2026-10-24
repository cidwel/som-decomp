.setcpu "65816"
.segment "CODE"
.org $14FB
map_control_0d14fb:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
