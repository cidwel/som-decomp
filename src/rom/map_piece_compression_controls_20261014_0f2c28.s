.setcpu "65816"
.segment "CODE"
.org $2C28
map_control_0f2c28:
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
