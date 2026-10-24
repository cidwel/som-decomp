.setcpu "65816"
.segment "CODE"
.org $F654
map_control_0ff654:
    .byte $E6 ; previous-row copy count
