.setcpu "65816"
.segment "CODE"
.org $718C
map_control_0c718c:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
