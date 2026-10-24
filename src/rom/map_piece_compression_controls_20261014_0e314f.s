.setcpu "65816"
.segment "CODE"
.org $314F
map_control_0e314f:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
