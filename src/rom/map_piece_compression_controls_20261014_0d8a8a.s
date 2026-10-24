.setcpu "65816"
.segment "CODE"
.org $8A8A
map_control_0d8a8a:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
