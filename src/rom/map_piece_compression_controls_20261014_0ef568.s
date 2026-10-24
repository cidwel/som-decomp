.setcpu "65816"
.segment "CODE"
.org $F568
map_control_0ef568:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
