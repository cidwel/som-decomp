.setcpu "65816"
.segment "CODE"
.org $A122
map_control_0ea122:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
