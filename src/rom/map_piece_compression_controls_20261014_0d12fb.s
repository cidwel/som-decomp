.setcpu "65816"
.segment "CODE"
.org $12FB
map_control_0d12fb:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
