.setcpu "65816"
.segment "CODE"
.org $8664
map_control_0e8664:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
