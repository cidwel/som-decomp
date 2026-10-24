.setcpu "65816"
.segment "CODE"
.org $BD14
map_control_0dbd14:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
