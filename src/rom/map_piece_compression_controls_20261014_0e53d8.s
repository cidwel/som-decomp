.setcpu "65816"
.segment "CODE"
.org $53D8
map_control_0e53d8:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
