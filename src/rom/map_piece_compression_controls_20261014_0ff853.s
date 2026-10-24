.setcpu "65816"
.segment "CODE"
.org $F853
map_control_0ff853:
    .byte $E6 ; previous-row copy count
