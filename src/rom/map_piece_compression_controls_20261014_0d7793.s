.setcpu "65816"
.segment "CODE"
.org $7793
map_control_0d7793:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
