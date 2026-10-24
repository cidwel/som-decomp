.setcpu "65816"
.segment "CODE"
.org $A50F
map_control_0ea50f:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
