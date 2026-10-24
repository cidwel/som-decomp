.setcpu "65816"
.segment "CODE"
.org $CA2F
map_control_0eca2f:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
