.setcpu "65816"
.segment "CODE"
.org $F503
map_control_0ff503:
    .byte $E3 ; previous-row copy count
