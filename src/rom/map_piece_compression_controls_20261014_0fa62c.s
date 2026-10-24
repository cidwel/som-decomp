.setcpu "65816"
.segment "CODE"
.org $A62C
map_control_0fa62c:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
