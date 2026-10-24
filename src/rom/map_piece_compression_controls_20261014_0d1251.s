.setcpu "65816"
.segment "CODE"
.org $1251
map_control_0d1251:
    .byte $E0 ; previous-row copy escape
    .byte $A3 ; row-distance/count
