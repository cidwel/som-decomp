.setcpu "65816"
.segment "CODE"
.org $7CA1
map_control_0d7ca1:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
