.setcpu "65816"
.segment "CODE"
.org $3E2C
map_control_0e3e2c:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
