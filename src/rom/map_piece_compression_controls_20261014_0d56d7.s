.setcpu "65816"
.segment "CODE"
.org $56D7
map_control_0d56d7:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A7 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
