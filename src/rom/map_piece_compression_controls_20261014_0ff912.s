.setcpu "65816"
.segment "CODE"
.org $F912
map_control_0ff912:
    .byte $E2 ; previous-row copy count
