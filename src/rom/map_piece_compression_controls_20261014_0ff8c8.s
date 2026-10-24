.setcpu "65816"
.segment "CODE"
.org $F8C8
map_control_0ff8c8:
    .byte $E3 ; previous-row copy count
