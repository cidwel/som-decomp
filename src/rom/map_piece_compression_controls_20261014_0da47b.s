.setcpu "65816"
.segment "CODE"
.org $A47B
map_control_0da47b:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $E7 ; previous-row copy count
