.setcpu "65816"
.segment "CODE"
.org $405F
map_control_0c405f:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
