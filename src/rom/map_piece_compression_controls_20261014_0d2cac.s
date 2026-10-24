.setcpu "65816"
.segment "CODE"
.org $2CAC
map_control_0d2cac:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
