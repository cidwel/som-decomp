.setcpu "65816"
.segment "CODE"
.org $A528
map_control_0ea528:
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
