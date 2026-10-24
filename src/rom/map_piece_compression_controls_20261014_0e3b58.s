.setcpu "65816"
.segment "CODE"
.org $3B58
map_control_0e3b58:
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
