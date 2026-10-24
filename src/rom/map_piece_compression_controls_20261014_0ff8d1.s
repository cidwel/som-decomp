.setcpu "65816"
.segment "CODE"
.org $F8D1
map_control_0ff8d1:
    .byte $E3 ; previous-row copy count
