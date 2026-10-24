.setcpu "65816"
.segment "CODE"
.org $760D
map_control_0e760d:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
