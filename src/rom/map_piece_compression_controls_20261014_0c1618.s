.setcpu "65816"
.segment "CODE"
.org $1618
map_control_0c1618:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
