.setcpu "65816"
.segment "CODE"
.org $F4FE
map_control_0cf4fe:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
    .byte $E5 ; previous-row copy count
