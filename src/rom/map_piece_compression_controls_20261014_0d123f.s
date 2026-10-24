.setcpu "65816"
.segment "CODE"
.org $123F
map_control_0d123f:
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
