.setcpu "65816"
.segment "CODE"
.org $A4B6
map_control_0da4b6:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
