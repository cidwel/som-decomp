.setcpu "65816"
.segment "CODE"
.org $A33C
map_control_0ea33c:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
