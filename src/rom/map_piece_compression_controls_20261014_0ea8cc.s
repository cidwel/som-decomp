.setcpu "65816"
.segment "CODE"
.org $A8CC
map_control_0ea8cc:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
