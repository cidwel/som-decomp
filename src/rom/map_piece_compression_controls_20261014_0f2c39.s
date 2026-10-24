.setcpu "65816"
.segment "CODE"
.org $2C39
map_control_0f2c39:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
