.setcpu "65816"
.segment "CODE"
.org $A41F
map_control_0ea41f:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
