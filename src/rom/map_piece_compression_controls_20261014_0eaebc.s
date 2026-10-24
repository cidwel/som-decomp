.setcpu "65816"
.segment "CODE"
.org $AEBC
map_control_0eaebc:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
