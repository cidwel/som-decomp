.setcpu "65816"
.segment "CODE"
.org $A7A1
map_control_0fa7a1:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
