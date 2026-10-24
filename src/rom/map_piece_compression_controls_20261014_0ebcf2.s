.setcpu "65816"
.segment "CODE"
.org $BCF2
map_control_0ebcf2:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
