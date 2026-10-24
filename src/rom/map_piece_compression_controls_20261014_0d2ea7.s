.setcpu "65816"
.segment "CODE"
.org $2EA7
map_control_0d2ea7:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
