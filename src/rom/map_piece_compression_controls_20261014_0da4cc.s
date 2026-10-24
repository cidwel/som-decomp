.setcpu "65816"
.segment "CODE"
.org $A4CC
map_control_0da4cc:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
