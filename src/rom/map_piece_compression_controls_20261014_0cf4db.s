.setcpu "65816"
.segment "CODE"
.org $F4DB
map_control_0cf4db:
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
    .byte $E3 ; previous-row copy count
