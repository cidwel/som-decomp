.setcpu "65816"
.segment "CODE"
.org $A794
map_control_0da794:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
