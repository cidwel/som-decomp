.setcpu "65816"
.segment "CODE"
.org $F57F
map_control_0ef57f:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
