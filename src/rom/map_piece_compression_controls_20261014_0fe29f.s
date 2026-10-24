.setcpu "65816"
.segment "CODE"
.org $E29F
map_control_0fe29f:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
