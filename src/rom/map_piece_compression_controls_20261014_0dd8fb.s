.setcpu "65816"
.segment "CODE"
.org $D8FB
map_control_0dd8fb:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
