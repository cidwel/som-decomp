.setcpu "65816"
.segment "CODE"
.org $2C8A
map_control_0d2c8a:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
