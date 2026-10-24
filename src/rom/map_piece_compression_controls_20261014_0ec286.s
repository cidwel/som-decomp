.setcpu "65816"
.segment "CODE"
.org $C286
map_control_0ec286:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $A0 ; row-distance/count
