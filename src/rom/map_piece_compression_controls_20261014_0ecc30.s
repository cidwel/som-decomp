.setcpu "65816"
.segment "CODE"
.org $CC30
map_control_0ecc30:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
