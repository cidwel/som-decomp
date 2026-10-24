.setcpu "65816"
.segment "CODE"
.org $F72F
map_control_0ef72f:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
