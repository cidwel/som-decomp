.setcpu "65816"
.segment "CODE"
.org $A260
map_control_0fa260:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
