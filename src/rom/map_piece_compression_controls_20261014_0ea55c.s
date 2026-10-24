.setcpu "65816"
.segment "CODE"
.org $A55C
map_control_0ea55c:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
