.setcpu "65816"
.segment "CODE"
.org $CCC4
map_control_0fccc4:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
