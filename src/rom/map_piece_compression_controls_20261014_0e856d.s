.setcpu "65816"
.segment "CODE"
.org $856D
map_control_0e856d:
    .byte $E0 ; previous-row copy escape
    .byte $A6 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $E3 ; row-distance/count
