.setcpu "65816"
.segment "CODE"
.org $F6FE
map_control_0ff6fe:
    .byte $E6 ; previous-row copy count
