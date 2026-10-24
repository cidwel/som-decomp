.setcpu "65816"
.segment "CODE"
.org $A436
map_control_0da436:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
