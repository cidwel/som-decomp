.setcpu "65816"
.segment "CODE"
.org $D7FB
map_control_0ed7fb:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
