.setcpu "65816"
.segment "CODE"
.org $CAFC
map_control_0fcafc:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
