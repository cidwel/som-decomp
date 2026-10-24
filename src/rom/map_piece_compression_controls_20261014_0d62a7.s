.setcpu "65816"
.segment "CODE"
.org $62A7
map_control_0d62a7:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
