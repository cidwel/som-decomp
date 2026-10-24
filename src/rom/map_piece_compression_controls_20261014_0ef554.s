.setcpu "65816"
.segment "CODE"
.org $F554
map_control_0ef554:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
