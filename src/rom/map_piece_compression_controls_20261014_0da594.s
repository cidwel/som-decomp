.setcpu "65816"
.segment "CODE"
.org $A594
map_control_0da594:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
