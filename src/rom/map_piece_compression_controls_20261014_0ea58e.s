.setcpu "65816"
.segment "CODE"
.org $A58E
map_control_0ea58e:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
