.setcpu "65816"
.segment "CODE"
.org $7BC6
map_control_0e7bc6:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
