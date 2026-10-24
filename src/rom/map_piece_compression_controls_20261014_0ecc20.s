.setcpu "65816"
.segment "CODE"
.org $CC20
map_control_0ecc20:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
