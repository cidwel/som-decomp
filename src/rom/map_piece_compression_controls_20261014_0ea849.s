.setcpu "65816"
.segment "CODE"
.org $A849
map_control_0ea849:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
