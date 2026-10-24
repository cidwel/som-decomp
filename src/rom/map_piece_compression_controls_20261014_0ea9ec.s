.setcpu "65816"
.segment "CODE"
.org $A9EC
map_control_0ea9ec:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
