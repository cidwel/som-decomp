.setcpu "65816"
.segment "CODE"
.org $F8DA
map_control_0ff8da:
    .byte $E3 ; previous-row copy count
