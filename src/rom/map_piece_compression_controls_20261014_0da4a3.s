.setcpu "65816"
.segment "CODE"
.org $A4A3
map_control_0da4a3:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
