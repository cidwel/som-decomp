.setcpu "65816"
.segment "CODE"
.org $BDB7
map_control_0ebdb7:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A5 ; row-distance/count
