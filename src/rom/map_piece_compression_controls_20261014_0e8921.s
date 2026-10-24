.setcpu "65816"
.segment "CODE"
.org $8921
map_control_0e8921:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
