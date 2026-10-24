.setcpu "65816"
.segment "CODE"
.org $A8E2
map_control_0ea8e2:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
