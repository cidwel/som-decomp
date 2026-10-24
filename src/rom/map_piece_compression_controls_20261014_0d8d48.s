.setcpu "65816"
.segment "CODE"
.org $8D48
map_control_0d8d48:
    .byte $F3 ; progressive-copy count
    .byte $E1 ; previous-row copy count
