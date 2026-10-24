.setcpu "65816"
.segment "CODE"
.org $CC3E
map_control_0ecc3e:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
