.setcpu "65816"
.segment "CODE"
.org $E763
map_control_0fe763:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
