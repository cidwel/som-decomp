.setcpu "65816"
.segment "CODE"
.org $6650
map_control_0c6650:
    .byte $E2 ; previous-row copy count
    .byte $F1 ; progressive-copy count
