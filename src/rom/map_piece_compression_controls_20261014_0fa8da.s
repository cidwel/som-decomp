.setcpu "65816"
.segment "CODE"
.org $A8DA
map_control_0fa8da:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
