.setcpu "65816"
.segment "CODE"
.org $F552
map_control_0ff552:
    .byte $E1 ; previous-row copy count
