.setcpu "65816"
.segment "CODE"
.org $8414
map_control_0c8414:
    .byte $F1 ; progressive-copy count
    .byte $E6 ; previous-row copy count
