.setcpu "65816"
.segment "CODE"
.org $F4C7
map_control_0ff4c7:
    .byte $E4 ; previous-row copy count
