.setcpu "65816"
.segment "CODE"
.org $A25F
map_control_0da25f:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
