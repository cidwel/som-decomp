.setcpu "65816"
.segment "CODE"
.org $9480
map_control_0d9480:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
