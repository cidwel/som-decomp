.setcpu "65816"
.segment "CODE"
.org $4541
map_control_0e4541:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
