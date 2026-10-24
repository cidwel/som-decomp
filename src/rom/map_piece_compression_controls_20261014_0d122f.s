.setcpu "65816"
.segment "CODE"
.org $122F
map_control_0d122f:
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count
