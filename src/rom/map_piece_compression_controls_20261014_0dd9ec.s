.setcpu "65816"
.segment "CODE"
.org $D9EC
map_control_0dd9ec:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
