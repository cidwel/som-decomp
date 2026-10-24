.setcpu "65816"
.segment "CODE"
.org $CAAA
map_control_0fcaaa:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
