.setcpu "65816"
.segment "CODE"
.org $4B3F
map_control_0e4b3f:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
