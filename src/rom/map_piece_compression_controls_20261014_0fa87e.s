.setcpu "65816"
.segment "CODE"
.org $A87E
map_control_0fa87e:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
