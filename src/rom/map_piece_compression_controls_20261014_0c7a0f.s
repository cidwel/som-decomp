.setcpu "65816"
.segment "CODE"
.org $7A0F
map_control_0c7a0f:
    .byte $F3 ; progressive-copy count
    .byte $E3 ; previous-row copy count
