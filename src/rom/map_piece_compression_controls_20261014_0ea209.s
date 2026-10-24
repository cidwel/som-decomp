.setcpu "65816"
.segment "CODE"
.org $A209
map_control_0ea209:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
