.setcpu "65816"
.segment "CODE"
.org $A46F
map_control_0da46f:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
