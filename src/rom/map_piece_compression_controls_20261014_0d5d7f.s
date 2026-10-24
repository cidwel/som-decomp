.setcpu "65816"
.segment "CODE"
.org $5D7F
map_control_0d5d7f:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
